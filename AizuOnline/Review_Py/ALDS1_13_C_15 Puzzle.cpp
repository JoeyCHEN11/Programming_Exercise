#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <functional>
#include <queue>

using namespace std;

//move space to : up, left, down, right
const static char direction[] { 'u', 'l', 'd', 'r'};
const int dir_y[] {-1, 0, 1, 0};
const int dir_x[] {0, -1, 0, 1};

const static int MAX_LIMIT = 45;
static const int N = 4;
static const int N2 = N * N;

class NPuzzle{
public:
    //直接开数组，vector会爆内存，且时间不够
    int board[N2];
    int space;
    int md;
    int cost;
    
    int& operator [](int idx){ return board[idx]; }
    //operators for map and pq
    bool operator == (const NPuzzle & p) const { return equal(board, board + N2, p.board); };
    bool operator < (const NPuzzle & p ) const {
        for(int i = 0; i < N2; i++){
            if(board[i] == p.board[i]) continue;
            return board[i] < p.board[i];
        }
        return false;
    };
    void move_to(int new_space){
        swap(board[space], board[new_space]);
        space = new_space;
    }
};

struct PuzzleState
{
    //如使用指针，反而会增加内存，且复制NPuzzle成本不高
    NPuzzle p;
    int estimated;

    bool operator > (const PuzzleState & ps) const { return estimated > ps.estimated; }
};

class NPuzzleSolve
{
private:
    int limit;
    //current-correct position (symmetric)
    int MDT[N2][N2];

    NPuzzle idaState;
    string idaPath;

public:
    NPuzzleSolve(){
        //current position
        for(int i = 0; i < N2; i++){
            //correct position
            for(int j = 0; j < N2; j++){
                MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
            }
        }
        idaPath.resize(MAX_LIMIT);
    };

    int getAllMDT(NPuzzle & p){
        int sum = 0;
        for(int i = 0; i < N2; i++){
            if(p[i] != 0) sum += MDT[i][p[i] - 1];
        }
        return sum;
    }

    bool dfs(int depth, int prevDir){
        if(idaState.md == 0) return true;
        if(depth + idaState.md > limit) return false;

        NPuzzle temp = idaState;
        
        int sx = idaState.space % N;
        int sy = idaState.space / N;
        
        for(int r = 0; r < 4; r ++){
            int tx = sx + dir_x[r];
            int ty = sy + dir_y[r];
            if(abs(prevDir - r) == 2 || tx < 0 || tx >= N || ty < 0 || ty >= N) continue;
            
            idaState.md -= MDT[ty * N + tx][idaState[ty * N + tx] - 1];
            idaState.md += MDT[idaState.space][idaState[ty * N + tx] - 1];
            //cout<<idaState.md<<endl;
            idaState.move_to(ty * N + tx);
            if(dfs(depth + 1, r)) {
                idaPath[depth] = direction[r];
                return true;
            }
            idaState = temp;

        }
        return false;
    }

    string idaStar(NPuzzle& r){
        idaState = r;
        idaState.md = getAllMDT(r);
        //cout<<idaState.md<<endl;
        for(limit = idaState.md; limit <= MAX_LIMIT; limit++){
            if(dfs(0, -10)) {
                idaPath.resize(limit);
                return idaPath;
            }
        }
        return "no solution";
    }

    int aStar(NPuzzle& r){
        priority_queue<PuzzleState, vector<PuzzleState>, greater<PuzzleState>> pq;
        map<NPuzzle, bool> check;

        r.md = getAllMDT(r);
        r.cost = 0;
        int tryTime = 0;
        PuzzleState initState;
        initState.p = r;
        initState.estimated = r.md;
        pq.emplace(initState);
        check[r] = true;

        NPuzzle u,v;
        while(!pq.empty()){
            PuzzleState st = pq.top(); pq.pop();
            u = st.p;
            //cout<<st.estimated<<endl;
            if(u.md == 0) {
                //cout<<"found, tried "<<tryTime<<"times"<<endl;
                //check.clear();
                //cout<<"map clear"<<endl;
                return u.cost;
            }
            int sx = u.space % N;
            int sy = u.space / N;
            for(int r = 0; r < 4; r++){
                int tx = sx + dir_x[r];
                int ty = sy + dir_y[r];
                if(tx < 0 || tx >= N || ty < 0 || ty >= N) continue;
                v = u;
                v.md -= MDT[ty * N + tx][v[ty * N + tx] - 1];
                v.md += MDT[v.space][v[ty * N + tx] - 1];
                v.move_to(ty * N + tx);
                //cout<<((v == u)? "equal" : "")<<endl;
                if(!check[v]){
                    //tryTime++;
                    v.cost++;
                    check[v] = true;
                    PuzzleState newst;
                    newst.p = v;
                    newst.estimated = v.md + v.cost;
                    pq.push(newst);
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    NPuzzle p;
    NPuzzleSolve nps;
    for(int i = 0; i < N2; i++){
        cin>>p[i];
        if(p[i] == 0) p.space = i;
    }
    int res = nps.aStar(p);
    //cout<<"function quit"<<endl;
    cout<<res<<endl;
    return 0;
}

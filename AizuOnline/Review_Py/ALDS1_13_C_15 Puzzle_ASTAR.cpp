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

struct NPuzzle{
    int board[16];
    int space;
    int md;
    int cost;
    
    bool operator < (const NPuzzle & p ) const {
        //int b_n = min(board_n, p.board_n);
        for(int i = 0; i < 16; i++){
            if(board[i] == p.board[i]) continue;
            return board[i] < p.board[i];
        }
        return false;
    }
};

struct PuzzleState
{
    NPuzzle p;
    int estimated;

    bool operator > (const PuzzleState & ps) const { return estimated > ps.estimated; }
};

class NPuzzleSolve
{
private:
    
    int n;
    int n2;
    //current-correct position (symmetric)
    vector<vector<int>> MDT;
public:
    NPuzzleSolve(int size = 3) : n(size), n2(size * size){
        MDT.resize(n2, vector<int>(n2));
        //current position
        for(int i = 0; i < n2; i++){
            //correct position
            for(int j = 0; j < n2; j++){
                MDT[i][j] = abs(i / n - j / n) + abs(i % n - j % n);
            }
        }
    };

    int getAllMDT(NPuzzle & p){
        int sum = 0;
        for(int i = 0; i < n2; i++){
            if(p.board[i] != 0) sum += MDT[i][p.board[i] - 1];
        }
        return sum;
    }

    int astar(NPuzzle& r){
        priority_queue<PuzzleState, vector<PuzzleState>, greater<PuzzleState>> pq;
        map<NPuzzle, bool> check;

        r.md = getAllMDT(r);
        r.cost = 0;
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
            if(u.md == 0) return u.cost;

            int sx = u.space % n;
            int sy = u.space / n;
            for(int r = 0; r < 4; r++){
                int tx = sx + dir_x[r];
                int ty = sy + dir_y[r];
                if(tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                v = u;
                v.md -= MDT[ty * n + tx][v.board[ty * n + tx] - 1];
                v.md += MDT[v.space][v.board[ty * n + tx] - 1];
                swap(v.board[v.space], v.board[ty * n + tx]);
                v.space = ty * n + tx;
                //cout<<((v == u)? "equal" : "")<<endl;
                if(!check[v]){
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
    int n = 4;
    NPuzzle p;
    //p.board.resize(n * n);
    NPuzzleSolve nps(n);
    for(int i = 0; i < n * n; i++){
        cin>>p.board[i];
        if(p.board[i] == 0) p.space = i;
    }
    cout<<nps.astar(p)<<endl;
    return 0;
}

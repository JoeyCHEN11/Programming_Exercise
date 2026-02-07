#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <functional>
#include <queue>

using namespace std;


static const char direction[] { 'u', 'l', 'd', 'r'};
static const int dir_y[] {-1, 0, 1, 0};
static const int dir_x[] {0, -1, 0, 1};
class N_Puzzle
{
private:
    int n;
    int board_n;
    vector<int> board;
    int space;

    //move space to : up, left, down, right

    string path;

public:

    N_Puzzle(int size = 3): n(size){
        board_n = n * n;
        board.resize(board_n);
    };
    int& operator [](int idx){ return board[idx]; }
    //operators for map
    bool operator == (const N_Puzzle & p) const { return equal(board.begin(), board.end(), p.board.begin()); };
    bool operator < (const N_Puzzle & p ) const {
        int b_n = min(board_n, p.board_n);
        for(int i = 0; i < b_n; i++){
            if(board[i] == p.board[i]) continue;
            else return board[i] < p.board[i];
        }
        return board_n < p.board_n;
    };
    bool operator > (const N_Puzzle & p ) const {
        int b_n = min(board_n, p.board_n);
        for(int i = 0; i < b_n; i++){
            if(board[i] == p.board[i]) continue;
            else return board[i] > p.board[i];
        }
        return board_n > p.board_n;
    };

    void set_space(int _space){ space = _space; }

    bool movable(int d_x, int d_y){ return d_x >= 0 && d_x < n && d_y >= 0 && d_y < n;}
    bool movable(int dir){ return movable(space % n + dir_x[dir], space / n + dir_y[dir]); }

    void move_toawrd(int dir){
        int t_x = space % n + dir_x[dir];
        int t_y = space / n + dir_y[dir];
        swap(board[space], board[t_y * n + t_x]);
        space = t_y * n + t_x; 
        path.push_back(direction[dir]);
    }

    bool solved(){
        // for(int b : board) cout<<b<<" ";
        // cout<<endl;
        for(int i = 0; i < board.size(); i++){
            if(board[i] != (i + 1) % board.size()) return false;
        }

        return true;
    }

    string bfs_solve_n_puzzle(){

        map<N_Puzzle, bool> check;
        queue<N_Puzzle> bfs_q;
        N_Puzzle u,v;
        bfs_q.emplace(*this);
        while(!bfs_q.empty()){
            u = bfs_q.front(); bfs_q.pop();

            if(u.solved()) return u.path;
            else for(int dir = 0; dir < 4; dir++){
                if(!u.movable(dir)) continue;
                else {
                    v = u;
                    // v.solved();
                    v.move_toawrd(dir);
                    // cout<<v.path<<endl;
                    if(!check[v]){
                        bfs_q.emplace(v);
                        check[v] = true;
                    }//else cout<<"Checked"<<endl;
                }
            }
        }
        return "no solution";
    }
};

int main(int argc, char const *argv[])
{
    N_Puzzle p;

    for(int i = 0; i < 9; i++){
        cin>>p[i];
        if(p[i] == 0) p.set_space(i);
    }
    cout<<p.bfs_solve_n_puzzle().size()<<endl;
    return 0;
}

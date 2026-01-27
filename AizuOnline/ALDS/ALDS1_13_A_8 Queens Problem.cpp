#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class QueenBoard{
private:
    enum status {FREE, NOT_FREE};
    int n;
    bool solved;
    vector<vector<bool>> board;
    vector<status> row;
    vector<status> col;
    //↙ diagonals (i + j)
    vector<status> dpos;
    //↘ diagonals (i - j + (N - 1))
    vector<status> dneg;
public:
    QueenBoard(int size = 8) : n(size) {
        board.resize(n, vector<bool>(n, false));
        row.resize(n, FREE);
        col.resize(n, FREE);
        dpos.resize(2 * n - 1, FREE);
        dneg.resize(2 * n - 1, FREE);
        solved = false;

    };

    bool is_free(int r, int c){
        return row[r] == FREE && col[c] == FREE && dpos[r + c] == FREE && dneg[r - c + n - 1] == FREE;
    }

    void set_up(int r, int c){
        board[r][c] = true;

        row[r] = col[c] = dpos[r + c] = dneg[r - c + n - 1] = NOT_FREE;
    }

    void remove(int r, int c){
        board[r][c] = false;

        row[r] = col[c] = dpos[r + c] = dneg[r - c + n - 1] = FREE;
    }

    void print_board(){
        //cout<<"board n: " <<n;
        for(auto r : board){
            for(bool q : r){
                cout<<(q? "Q" : ".");
            }
            cout<<'\n';
        }
    }

    void solve_n_queens(int r){
        if(r >= n){
            print_board();
            //cancel this line: back to origin status; 
            solved = true;
            return;  
        }
        if(row[r] == NOT_FREE) solve_n_queens(r + 1);
        else{
            for(int c = 0; c < n; c++){
                if(is_free(r, c)){
                    set_up(r, c);
                    //cout<<r<<" "<<c<<endl;
                    solve_n_queens(r + 1);
                    if(!solved) remove(r, c);
                    else return;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int k, r, c;
    QueenBoard qb;
    cin>>k;
    while(k--){
        cin>>r>>c;
        qb.set_up(r, c);
    }
    //qb.print_board();
    qb.solve_n_queens(0);
    //cout<<endl;
    //qb.print_board();
    return 0;
}

/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (67.38%)
 * Likes:    11933
 * Dislikes: 267
 * Total Accepted:    675.5K
 * Total Submissions: 1M
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [["Q"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
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

        row[r] = NOT_FREE;
        col[c] = NOT_FREE;
        dpos[r + c] = NOT_FREE;
        dneg[r - c + n - 1] = NOT_FREE;
    }

    void remove(int r, int c){
        board[r][c] = false;

        row[r] = FREE;
        col[c] = FREE;
        dpos[r + c] = FREE;
        dneg[r - c + n - 1] = FREE;
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

    void record_ans(vector<vector<string>>& ans){
        vector<string> ans_s;
        for(int r = 0; r < n; r++){
            string s(n, '.');
            for(int c = 0; c < n; c++){
                if(board[r][c]) s[c] = 'Q';
            }
            ans_s.push_back(s);
        }
        ans.push_back(ans_s);
    }

    void solve_8_queens(int r, vector<vector<string>> & ans){
        if(r >= n){
            //print_board();
            //cancel this line: back to origin status; 
            //solved = true;
            record_ans(ans);
            return;  
        }
        if(row[r] == NOT_FREE) solve_8_queens(r + 1, ans);
        else{
            for(int c = 0; c < n; c++){
                if(is_free(r, c)){
                    set_up(r, c);
                    //cout<<r<<" "<<c<<endl;
                    solve_8_queens(r+1, ans);
                    if(!solved) remove(r, c);
                    else return;
                }
            }
        }
    }
};


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        QueenBoard qb(n);
        qb.solve_8_queens(0, ans);
        return ans;
    }
};
// @lc code=end


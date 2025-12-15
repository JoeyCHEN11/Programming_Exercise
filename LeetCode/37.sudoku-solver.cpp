/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (60.20%)
 * Likes:    9231
 * Dislikes: 242
 * Total Accepted:    550.9K
 * Total Submissions: 912.6K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * The '.' character indicates empty cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Sudoku{
private:
    int n, n2;
    enum status {FREE, NOT_FREE};
    //row check : FREE - the num is setable, NOT_FREE - already filled
    vector<vector<status>> row, col;
    vector<vector<vector<status>>> block;

public:
    vector<vector<int>> board;
    Sudoku(int _n = 3) : n(_n), n2(n * n){
        board.resize(n2, vector<int>(n2, 0));
        row.resize(n2, vector<status>(n2, FREE));
        col.resize(n2, vector<status>(n2, FREE));
        block.resize(n, vector<vector<status>>(n, vector<status>(n2, FREE)));
    };

    void printBoard(){
        for(const auto & r : board){
            for(auto num : r){
                cout<<num<<" ";
            }
            cout<<endl;
        }
    }

    bool isValid(int r, int c, int num){
        return row[r][num - 1] == FREE &&
                col[c][num - 1] == FREE &&
                block[r / n][c / n][num - 1] == FREE;
    }

    void setNum(int r, int c, int num){
        if(num > n2 || num < 1) return;

        board[r][c] = num;

        row[r][num - 1] = NOT_FREE;
        col[c][num - 1] = NOT_FREE;

        block[r/n][c/n][num - 1] = NOT_FREE;
    }

    void removeNum(int r, int c){
        int num = board[r][c];

        row[r][num - 1] = FREE;
        col[c][num - 1] = FREE;

        block[r/n][c/n][num - 1] = FREE;

        board[r][c] = 0;
    }

    bool solve(int r, int c){
        if(r >= n2) return true;
        
        if(c >= n2) return solve(r + 1, 0);

        if(board[r][c] != 0) return solve(r, c + 1);

        for(int num = 1; num <= n2; num++){
            if(isValid(r, c, num)){
                setNum(r, c, num);
                if(solve(r, c + 1)) return true;
                else removeNum(r, c);
            }
        }
        return false;
    }
};


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int SIZE = board.size();
        Sudoku sudoku;
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                if(isdigit(board[i][j])){
                    sudoku.setNum(i, j, board[i][j] - '0');
                }
            }
        }

        sudoku.solve(0, 0);
        
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                board[i][j] = '0' + sudoku.board[i][j];
            }
        }
    }
};
// @lc code=end


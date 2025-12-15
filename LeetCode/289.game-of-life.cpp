/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (68.99%)
 * Likes:    6257
 * Dislikes: 551
 * Total Accepted:    461.1K
 * Total Submissions: 668K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * According to Wikipedia's article: "The Game of Life, also known simply as
 * Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 * 
 * The board is made up of an m x n grid of cells, where each cell has an
 * initial state: live (represented by a 1) or dead (represented by a 0). Each
 * cell interacts with its eight neighbors (horizontal, vertical, diagonal)
 * using the following four rules (taken from the above Wikipedia
 * article):
 * 
 * 
 * Any live cell with fewer than two live neighbors dies as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population.
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 * 
 * 
 * The next state is created by applying the above rules simultaneously to
 * every cell in the current state, where births and deaths occur
 * simultaneously. Given the current state of the m x n grid board, return the
 * next state.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
 * Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [[1,1],[1,0]]
 * Output: [[1,1],[1,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 25
 * board[i][j] is 0 or 1.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve it in-place? Remember that the board needs to be updated
 * simultaneously: You cannot update some cells first and then use their
 * updated values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches upon the border of the array (i.e., live cells reach the border).
 * How would you address these problems?
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;


// @lc code=start
class Solution {
public:

    int m, n;
    int dir[8][2]{ -1, 0, -1, 1,
                   0, 1, 1, 1,
                   1, 0, 1, -1, 
                   0, -1, -1, -1};
    bool boundCheck(int i, int j){ return i >= 0 && i < m && j >= 0 && j < n; }
    
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> change(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int neighbor = 0;
                for(auto [dx, dy] : dir){
                    if(boundCheck(i + dx, j + dy)){
                        neighbor += board[i + dx][j + dy];
                    }
                }

                if(board[i][j]){
                    if(neighbor < 2 || neighbor > 3)
                    change[i][j] = true;
                }else if(neighbor == 3) change[i][j] = true;
            }
        
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] ^= change[i][j];
            }
        }
    }
};
// @lc code=end


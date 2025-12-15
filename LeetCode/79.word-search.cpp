/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (41.46%)
 * Likes:    15037
 * Dislikes: 624
 * Total Accepted:    1.5M
 * Total Submissions: 3.6M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * 
 * 
 * 
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 * 
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int depth, m, n;
    vector<vector<bool>> visited;
    int dir[4][2] {-1, 0, 0, -1, 1, 0, 0, 1};

    bool boundCheck(int i, int j){ return i >= 0 && i < m && j >=0 && j < n; }
    bool searchWord(int k, int i, int j, const vector<vector<char>> & board, const string & word){
        if(word[k] != board[i][j]) return false;
        else if(k >= depth - 1) return true;
        
        for(auto [dx, dy] : dir){
            if(boundCheck(i + dx, j + dy) && !visited[i + dx][j + dy]){
                //可移到循环外侧，变为[i][j],也就是总体上延迟标记，延后回溯
                visited[i + dx][j + dy] = true;
                if(searchWord(k + 1, i + dx, j + dy , board, word)) return true;
                visited[i + dx][j + dy] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        depth = word.size();
        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if(searchWord(0, i, j, board, word)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
// @lc code=end


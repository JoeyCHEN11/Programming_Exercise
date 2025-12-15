/*
 * @lc app=leetcode id=2684 lang=cpp
 *
 * [2684] Maximum Number of Moves in a Grid
 *
 * https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/
 *
 * algorithms
 * Medium (45.45%)
 * Likes:    411
 * Dislikes: 6
 * Total Accepted:    22.9K
 * Total Submissions: 50.2K
 * Testcase Example:  '[[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]'
 *
 * You are given a 0-indexed m x n matrix grid consisting of positive
 * integers.
 * 
 * You can start at any cell in the first column of the matrix, and traverse
 * the grid in the following way:
 * 
 * 
 * From a cell (row, col), you can move to any of the cells: (row - 1, col +
 * 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell
 * you move to, should be strictly bigger than the value of the current cell.
 * 
 * 
 * Return the maximum number of moves that you can perform.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
 * Output: 3
 * Explanation: We can start at the cell (0, 0) and make the following moves:
 * - (0, 0) -> (0, 1).
 * - (0, 1) -> (1, 2).
 * - (1, 2) -> (2, 3).
 * It can be shown that it is the maximum number of moves that can be made.
 * 
 * Example 2:
 * 
 * 
 * 
 * Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
 * Output: 0
 * Explanation: Starting from any cell in the first column we cannot perform
 * any moves.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 2 <= m, n <= 1000
 * 4 <= m * n <= 10^5
 * 1 <= grid[i][j] <= 10^6
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) dp[i][0] = true;

        for(int j = 1; j < n; j++){
            bool reachable = false;
            for(int i = 0; i < m; i++){
                if(grid[i][j] > grid[i][j - 1]){
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
                if(i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1]){
                    dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
                }
                if(i + 1 < m && grid[i][j] > grid[i + 1][j - 1]){
                    dp[i][j] = dp[i][j] || dp[i + 1][j - 1];
                }
                reachable = reachable || dp[i][j];
            }
            if(!reachable) return j - 1;
        }

        return n - 1;
    }
};
// @lc code=end


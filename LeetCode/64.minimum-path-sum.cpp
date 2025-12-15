/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (63.64%)
 * Likes:    12221
 * Dislikes: 163
 * Total Accepted:    1.1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 200
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //int INF = 200 * 200 * 200 + 5;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for(int i = m - 2; i >= 0; i--) dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];
        for(int j = n - 2; j >= 0; j--) dp[m - 1][j] = grid[m - 1][j] + dp[m - 1][j + 1];
        
        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                dp[i][j] = min(dp[i + 1][j] + grid[i][j], dp[i][j + 1] + grid[i][j]);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end


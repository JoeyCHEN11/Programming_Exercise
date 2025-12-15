/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (64.01%)
 * Likes:    16237
 * Dislikes: 428
 * Total Accepted:    1.7M
 * Total Submissions: 2.7M
 * Testcase Example:  '3\n7'
 *
 * There is a robot on an m x n grid. The robot is initially located at the
 * top-left corner (i.e., grid[0][0]). The robot tries to move to the
 * bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
 * either down or right at any point in time.
 * 
 * Given the two integers m and n, return the number of possible unique paths
 * that the robot can take to reach the bottom-right corner.
 * 
 * The test cases are generated so that the answer will be less than or equal
 * to 2 * 10^9.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 7
 * Output: 28
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation: From the top-left corner, there are a total of 3 ways to reach
 * the bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 100
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> pathsDP(m, vector<int>(n, 1));

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                pathsDP[i][j] = pathsDP[i - 1][j] + pathsDP[i][j - 1];
            }
        }

        // vector<int> paths1D(n, 1);
        // for(int i = 1; i < m; i++){
        //     for(int j = 1; j < n; j++){
        //         paths1D[j] = paths1D[j] + paths1D[j - 1];
        //     }
        // }

        return pathsDP[m - 1][n - 1];
    }
};
// @lc code=end


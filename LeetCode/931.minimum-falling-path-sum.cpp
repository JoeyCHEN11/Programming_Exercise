/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (64.46%)
 * Likes:    6170
 * Dislikes: 156
 * Total Accepted:    417.5K
 * Total Submissions: 648.4K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * Given an n x n array of integers matrix, return the minimum sum of any
 * falling path through matrix.
 * 
 * A falling path starts at any element in the first row and chooses the
 * element in the next row that is either directly below or diagonally
 * left/right. Specifically, the next element from position (row, col) will be
 * (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * Output: 13
 * Explanation: There are two falling paths with a minimum sum as shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[-19,57],[-40,-5]]
 * Output: -59
 * Explanation: The falling path with a minimum sum is shown.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int minPath = matrix[i - 1][j];
                if(j > 0) minPath = min(minPath, matrix[i - 1][j - 1]); 
                if(j < n - 1) minPath = min(minPath, matrix[i - 1][j + 1]);
                matrix[i][j] += minPath;
            }
        }

        return *min_element(matrix.back().begin(), matrix.back().end());

    }
};
// @lc code=end


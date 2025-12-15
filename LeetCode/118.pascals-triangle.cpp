/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (73.98%)
 * Likes:    12556
 * Dislikes: 426
 * Total Accepted:    1.6M
 * Total Submissions: 2.2M
 * Testcase Example:  '5'
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 * 
 * 
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numRows <= 30
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows);
        //initialization
        for(int i = 0; i < numRows; i++){
            tri[i].resize(i + 1, 0);
            tri[i][0] = tri[i].back() = 1;
        }

        //generate
        for (int i = 2; i < numRows; i++) {
            for(int j = 1; j < i; j++){
                tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
            }
        }
        return tri;
    }
};
// @lc code=end


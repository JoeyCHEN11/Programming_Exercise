/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (59.90%)
 * Likes:    3388
 * Dislikes: 678
 * Total Accepted:    292.4K
 * Total Submissions: 487.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix mat, return an array of all the elements of the array
 * in a diagonal order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,4,7,5,3,6,8,9]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[1,2],[3,4]]
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -10^5 <= mat[i][j] <= 10^5
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        
        for(int diagnal = 0; diagnal < m + n - 1; diagnal++){
            // left down
            int i, j;
            if(diagnal & 1){
                j = min(diagnal, n - 1);
                i = diagnal - j;
                while(i < m && j >= 0){
                    ans.push_back(mat[i][j]);
                    i++; j--;
                }
            }else{
                i = min(diagnal, m - 1);
                j = diagnal - i;
                while(i >= 0 && j < n){
                    ans.push_back(mat[i][j]);
                    i--; j++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end


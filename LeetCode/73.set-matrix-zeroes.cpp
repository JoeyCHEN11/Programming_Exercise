/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (55.19%)
 * Likes:    14056
 * Dislikes: 709
 * Total Accepted:    1.3M
 * Total Submissions: 2.4M
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row
 * and column to 0's.
 * 
 * You must do it in place.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * A straightforward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    //O(1) Space
    void setZeroes(vector<vector<int>>& matrix) {
        bool setUp = false, setLeft = false;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if(!j) setLeft = true;
                    if(!i) setUp = true;
                }
            }
        }

        //set lines 0
        for (int i = 1; i < m; i++) {
            if(!matrix[i][0]){
                for(int j = 0; j < n; j++) matrix[i][j] = 0;
            }
        }

        //set columns 0
        for (int j = 1; j < n; j++) {
            if(!matrix[0][j]){
                for(int i = 0; i < m; i++) matrix[i][j] = 0;
            }
        }

        //set left bound
        if(setLeft){
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        //set up bound
        if(setUp){
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};
// @lc code=end


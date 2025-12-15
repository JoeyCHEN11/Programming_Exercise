/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (52.43%)
 * Likes:    11675
 * Dislikes: 196
 * Total Accepted:    908.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * Write an efficient algorithm that searches for a value target in an m x n
 * integer matrix matrix. This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 5
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix =
 * [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 * target = 20
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * All the integers in each row are sorted in ascending order.
 * All the integers in each column are sorted in ascending order.
 * -10^9 <= target <= 10^9
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    bool zSearchMatrix(vector<vector<int>>& matrix, int target){
        int m = matrix.size(), n = matrix[0].size();
        int right = n - 1, up = 0;
        while(right >=0 && up < m){
            if(matrix[up][right] > target) right--;
            else if(matrix[up][right] < target) up++;
            else return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int m = matrix.size(), n = matrix[0].size();
        // int right = n;
        // int up = 0, down = m, mid = 0;
        // while(up < down){
        //     mid = (up + down) / 2;
        //     if(matrix[mid].back() >= target) down = mid;
        //     else up = mid + 1;
        // }

        // for(int i = down; i < m; i++){
        //     auto it = lower_bound(matrix[i].begin(), matrix[i].begin() + right, target);
        //     if(*it == target) return true;
        //     else right = distance(matrix[i].begin(), it);
        // }

        return zSearchMatrix(matrix, target);
    }
};
// @lc code=end


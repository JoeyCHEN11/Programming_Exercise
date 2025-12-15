/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (46.09%)
 * Likes:    9834
 * Dislikes: 214
 * Total Accepted:    651.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given an m x n binary matrix filled with 0's and 1's, find the largest
 * square containing only 1's and return its area.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [["0","1"],["1","0"]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [["0"]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is '0' or '1'.
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int init(vector<vector<int>>& dp, const vector<vector<char>> & m){
        int h = m.size(), w = m[0].size();
        int init_max = 0;
        for(int i = 0; i < w; i++) {
            dp[0][i] = (m[0][i] == '1')? 1:0;
            init_max |= dp[0][i];
        }
        for(int i = 0; i < h; i++) {
            dp[i][0] = (m[i][0] == '1')? 1:0;
            init_max |= dp[i][0];
        }
        return init_max;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        vector<vector<int>> dp(h, vector<int>(w));
        
        int max_side = init(dp, matrix);
        for(int i = 1; i < h; i++){
            for(int j = 1; j < w; j++){
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    max_side = max(dp[i][j], max_side); 
                }
            }
        }
        return max_side * max_side;
    }
};
// @lc code=end


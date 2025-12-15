/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 *
 * https://leetcode.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (47.36%)
 * Likes:    5336
 * Dislikes: 446
 * Total Accepted:    196.2K
 * Total Submissions: 413.9K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * You are given an array of binary strings strs and two integers m and n.
 * 
 * Return the size of the largest subset of strs such that there are at most m
 * 0's and n 1's in the subset.
 * 
 * A set x is a subset of a set y if all elements of x are also elements of
 * y.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
 * Output: 4
 * Explanation: The largest subset with at most 5 0's and 3 1's is {"10",
 * "0001", "1", "0"}, so the answer is 4.
 * Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
 * {"111001"} is an invalid subset because it contains 4 1's, greater than the
 * maximum of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: strs = ["10","0","1"], m = 1, n = 1
 * Output: 2
 * Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 600
 * 1 <= strs[i].length <= 100
 * strs[i] consists only of digits '0' and '1'.
 * 1 <= m, n <= 100
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        //origin 3-d dp
        //int slen = strs.size();
        //vector<pair<int,int>> data;
        //for(const string & s : strs) data.emplace_back(count(s.begin(), s.end(), '0'), count(s.begin(), s.end(), '1'));
        // vector<vector<vector<int>>> dp(slen + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // //dp[0][0][0] = 0;
        // for (int i = 1; i <= slen; i++){
        //     for (int j = 0; j <= m ; j++){
        //         for (int k = 0; k <= n ; k++){
        //             auto [zeros, ones] = data[i - 1];
        //             if(j < zeros || k < ones) dp[i][j][k] = dp[i - 1][j][k];
        //             else dp[i][j][k] = max(dp[i - 1][j - zeros][k - ones] + 1, dp[i - 1][j][k]);         
        //         }
        //     }
        // }
        //return dp[slen][m][n];

        //optimize
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //dp[0][0] = 0;
        int zeros, ones;
        for (const string & s : strs){
            zeros = count(s.begin(), s.end(), '0');
            ones = s.size() - zeros;
            for (int j = m; j >= zeros ; j--){
                for (int k = n; k >= ones ; k--){
                    dp[j][k] = max(dp[j - zeros][k - ones] + 1, dp[j][k]);         
                }
            }
        }
        return dp[m][n];

    }
};
// @lc code=end


/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (37.41%)
 * Likes:    7927
 * Dislikes: 603
 * Total Accepted:    251.1K
 * Total Submissions: 671.3K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array of integers arr, find the sum of min(b), where b ranges over
 * every (contiguous) subarray of arr. Since the answer may be large, return
 * the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,1,2,4]
 * Output: 17
 * Explanation: 
 * Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
 * [3,1,2,4]. 
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
 * Sum is 17.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [11,81,94,43,3]
 * Output: 444
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 3 * 10^4
 * 1 <= arr[i] <= 3 * 10^4
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        int sum = accumulate(arr.begin(), arr.end(), 0) % MOD;

        //dp (out of memo)
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // for (int i = 0; i < n; i++) dp[i][i] = arr[i];

        // for (int len = 2; len <= n; len++) {
        //     for (int i = 0; i <= n - len; i++) {
        //         int j = i + len - 1;
        //         dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]);
        //         sum = (sum + dp[i][j]) % MOD;
        //     }
        // }

        //dp optimize
        vector<int> dp1D (arr.begin(), arr.end());
        for (int len = 2; len <= n; len++) {
            for (int i = n - len; i >= 0; i--) {
                int j = i + len - 1;
                dp1D[j] = min(dp1D[j], dp1D[j - 1]);
                sum = (sum + dp1D[j]) % MOD;
            }
        }

        return sum;
    }
};
// @lc code=end


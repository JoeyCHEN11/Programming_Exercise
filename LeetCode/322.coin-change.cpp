/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (43.48%)
 * Likes:    18470
 * Dislikes: 431
 * Total Accepted:    1.7M
 * Total Submissions: 3.9M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 * 
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        //int INF = INT32_MAX;
        //int n = coins.size();
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        // //dp[0][0] = 0;
        // for(int i = 1; i <= amount; i++) dp[0][i] = INF;
        
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= amount; j++){
        //         if(j < coins[i - 1] || dp[i][j - coins[i - 1]] == INF) dp[i][j] = dp[i-1][j];
        //         else dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
        //     }
        // }


        vector<int> dp1D(amount + 1, INT32_MAX);
        dp1D[0] = 0;
        
        for(int c : coins){
            for(int j = c; j <= amount; j++){
                if(dp1D[j - c] == INT32_MAX) continue;
                else dp1D[j] = min(dp1D[j], dp1D[j - c] + 1);
            }
        }

        return dp1D[amount] == INT32_MAX? -1 : dp1D[amount];
    }
};
// @lc code=end


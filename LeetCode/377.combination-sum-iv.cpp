/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (54.05%)
 * Likes:    7271
 * Dislikes: 651
 * Total Accepted:    470.8K
 * Total Submissions: 870.5K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an array of distinct integers nums and a target integer target, return
 * the number of possible combinations that add up to target.
 * 
 * The test cases are generated so that the answer can fit in a 32-bit
 * integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3], target = 4
 * Output: 7
 * Explanation:
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * Note that different sequences are counted as different combinations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [9], target = 3
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 1000
 * All the elements of nums are unique.
 * 1 <= target <= 1000
 * 
 * 
 * 
 * Follow up: What if negative numbers are allowed in the given array? How does
 * it change the problem? What limitation we need to add to the question to
 * allow negative numbers?
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        using ull = unsigned long long ;
        int n = nums.size();

        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        // dp[0][0] = 1;
        // for(int j = 0; j <= target; j++){
        //     for(int i = 1; i <= n; i++){
        //         //                    remove this part: use ull
        //         if(j < nums[i - 1] || dp[i-1][j] > INT32_MAX - dp[n][j - nums[i - 1]]) 
        //             dp[i][j] = dp[i-1][j];
        //         else dp[i][j] = dp[i-1][j] + dp[n][j - nums[i - 1]];
        //     }
        // }

        vector<ull> dp1D(target + 1, 0);
        dp1D[0] = 1;
        for(int t = 0; t <= target; t++){
            for(int num : nums){
                if(t >= num) dp1D[t] += dp1D[t - num];
            }
        }

        return dp1D[target];
    }
};
// @lc code=end


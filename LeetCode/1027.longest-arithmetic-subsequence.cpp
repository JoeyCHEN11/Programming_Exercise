/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 *
 * https://leetcode.com/problems/longest-arithmetic-subsequence/description/
 *
 * algorithms
 * Medium (49.03%)
 * Likes:    4615
 * Dislikes: 207
 * Total Accepted:    172.8K
 * Total Submissions: 352K
 * Testcase Example:  '[3,6,9,12]'
 *
 * Given an array nums of integers, return the length of the longest arithmetic
 * subsequence in nums.
 * 
 * Note that:
 * 
 * 
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining
 * elements.
 * A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value
 * (for 0 <= i < seq.length - 1).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,6,9,12]
 * Output: 4
 * Explanation:  The whole array is an arithmetic sequence with steps of length
 * = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [9,4,7,2,10]
 * Output: 3
 * Explanation:  The longest arithmetic subsequence is [4,7,10].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [20,1,15,3,10,5,8]
 * Output: 4
 * Explanation:  The longest arithmetic subsequence is [20,15,10,5].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 1000
 * 0 <= nums[i] <= 500
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), MAXNUM = 500;
        vector<vector<int>> dp(n, vector<int>(2 * MAXNUM + 1, 1));
        int ans = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                //                          offset
                int k = nums[i] - nums[j] + MAXNUM;
                dp[i][k] = max(dp[i][k], dp[j][k] + 1);
                ans = max(ans, dp[i][k]);
            }
        }
        return ans;
    }
};
// @lc code=end


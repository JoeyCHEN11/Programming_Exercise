/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (49.99%)
 * Likes:    2316
 * Dislikes: 179
 * Total Accepted:    256.6K
 * Total Submissions: 512.3K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * continuous increasing subsequence (i.e. subarray). The subsequence must be
 * strictly increasing.
 * 
 * A continuous increasing subsequence is defined by two indices l and r (l <
 * r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for
 * each l <= i < r, nums[i] < nums[i + 1].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,5,4,7]
 * Output: 3
 * Explanation: The longest continuous increasing subsequence is [1,3,5] with
 * length 3.
 * Even though [1,3,5,7] is an increasing subsequence, it is not continuous as
 * elements 5 and 7 are separated by element
 * 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,2,2,2,2]
 * Output: 1
 * Explanation: The longest continuous increasing subsequence is [2] with
 * length 1. Note that it must be strictly
 * increasing.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcisGreedy(vector<int> & nums){
        int n = nums.size();
        int maxLen = 1;
        int len = 1;
        for(int i = 1; i < n; i++){
            len = nums[i] > nums[i-1]? len + 1 : 1;
            maxLen = max(maxLen, len);
        }
        //maxLen = max(len, maxLen);
        return maxLen;
    }
     
    int lcisDP(vector<int> & nums){
        int n = nums.size();
        int maxLen = 1;
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            dp[i] = nums[i] > nums[i - 1]? dp[i - 1] + 1 : 1;
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }

    int findLengthOfLCIS(vector<int>& nums) {
        return lcisGreedy(nums);
    }
};
// @lc code=end


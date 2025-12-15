/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (50.56%)
 * Likes:    33218
 * Dislikes: 1394
 * Total Accepted:    3.7M
 * Total Submissions: 7.3M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the subarray with the largest sum, and
 * return its sum.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: 1
 * Explanation: The subarray [1] has the largest sum 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum;

        //greedy
        // int sum = nums[0];
        // maxSum = = nums[0];
        // for(int i = 1; i < nums.size(); i++){
        //     // if(sum < 0){
        //     //     sum = nums[i];
        //     // }else{
        //     //     sum += nums[i];
        //     // }
        //     sum = max(nums[i], sum + nums[i]);
        //     maxSum = max(sum, maxSum);
        // }

        //DP
        //the largest sum of subarray end with nums[i]
        vector<int> dp(nums.size(), 0);
        maxSum = dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(dp[i - 1] <= 0) dp[i] = nums[i];
            else dp[i] = nums[i] + dp[i - 1];

            maxSum = max(maxSum, dp[i]);
        }


        return maxSum;
    }
};
// @lc code=end


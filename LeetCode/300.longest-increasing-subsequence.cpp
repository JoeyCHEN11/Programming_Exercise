/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (54.88%)
 * Likes:    20436
 * Dislikes: 421
 * Total Accepted:    1.6M
 * Total Submissions: 2.9M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
 * complexity?
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lisGreedy(vector<int> & nums){
        vector<int> lenth;
        for(int num : nums){
            auto i = lower_bound(lenth.begin(), lenth.end(), num);
            if(i == lenth.end()){
                lenth.push_back(num);
            }else *i = num;
        }
        return lenth.size();
    }
    int lisDP(vector<int> & nums){
        int n = nums.size();
        vector<int> len(n, 1);
        int maxLen = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    len[i] = max(len[i], len[j] + 1);
                }
            }
            maxLen = max(maxLen, len[i]);
        }
        return maxLen;
    }
    int lengthOfLIS(vector<int>& nums) {
        return lisGreedy(nums);
    }
};
// @lc code=end


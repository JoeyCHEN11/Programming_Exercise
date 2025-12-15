/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (64.70%)
 * Likes:    18628
 * Dislikes: 579
 * Total Accepted:    2.7M
 * Total Submissions: 4.1M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array nums of size n, return the majority element.
 * 
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,3]
 * Output: 3
 * Example 2:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 * 
 * Follow-up: Could you solve the problem in linear time and in O(1) space?
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:

    int mooreVote(vector<int> & nums){
        int vote = 0, candidate = 0;
        for(int num : nums){
            if(vote == 0) candidate = num;
            vote += candidate == num? 1 : -1;
        }
        return candidate;
    }

    int majorityElement(vector<int>& nums) {
        // int right = nums.size();
        // int i = 0, j = 1;
        // while(j < right){
        //     while(nums[i] != nums[j]){
        //         swap(nums[--right], nums[j]);
        //         i++;
        //     }
        //     j++;
        // }
        // return nums[i];

        return mooreVote(nums);
    }
};
// @lc code=end


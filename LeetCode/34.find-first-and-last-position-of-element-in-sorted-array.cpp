/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int find_upper_bound(vector<int>& nums, int target ){
        if(nums.empty() || target < nums[0] || target > nums.back()) return -1;
        int left = 0, right = nums.size(), mid;
        while(left<right){
            mid = left + (right - left)/2;
            if(nums[mid] <= target) left = mid + 1;
            else  right = mid;
        }
        return nums[right-1] == target? right-1 : -1;
    }
    int find_lower_bound(vector<int>& nums, int target ){
        if(nums.empty() || target < nums[0] || target > nums.back())  return -1;
        int left = 0, right = nums.size(), mid;
        while(left<right){
            mid = left + (right - left)/2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return nums[left] == target? left : -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {find_lower_bound(nums, target), find_upper_bound(nums, target)};
    }
};
// @lc code=end


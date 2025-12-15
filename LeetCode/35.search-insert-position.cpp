/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0, right = nums.size(), mid;
        while(left<right){
            mid = left + (right + left)/2;
            if(nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid;
            else return mid;
        }
        return right;

        //return distance(nums.begin(),lower_bound(nums.begin(),nums.end(),target));
    }
};
// @lc code=end


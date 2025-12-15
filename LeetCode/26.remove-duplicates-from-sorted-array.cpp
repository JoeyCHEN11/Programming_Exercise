/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        for(int fast = slow + 1; fast < nums.size(); fast++ ){
            if(nums[slow] != nums[fast]) nums[++slow] = nums[fast];
        }
        return slow + 1;
    }
};
// @lc code=end


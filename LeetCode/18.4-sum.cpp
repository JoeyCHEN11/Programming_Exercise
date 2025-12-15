/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.05%)
 * Likes:    10934
 * Dislikes: 1330
 * Total Accepted:    891.3K
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers, return an array of all the unique
 * quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 
 * 
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * 
 * You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n - 3; i ++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if(nums[i] > target && nums[i] >= 0) break;
            for(int j = i + 1; j < n - 2; j ++){
                int left = j + 1, right = n - 1;
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if(nums[i] + nums[j] > target && nums[j] >= 0) break;
                while(right > left){
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right]; 
                    if(sum < target) left++;
                    else if(sum > target) right--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(right > left && nums[right] == nums[right - 1]) right--;
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        right--;
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end


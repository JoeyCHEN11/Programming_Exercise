/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (56.92%)
 * Likes:    9425
 * Dislikes: 286
 * Total Accepted:    861.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> subset;
    vector<vector<int>> ans;

    void buildPowerSet(int idx, const vector<int> & nums){
        ans.emplace_back(subset);

        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            buildPowerSet(i + 1, nums);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        buildPowerSet(0, nums);
        return ans;
    }
};
// @lc code=end


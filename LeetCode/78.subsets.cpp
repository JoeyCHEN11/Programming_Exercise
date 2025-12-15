/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (76.92%)
 * Likes:    16481
 * Dislikes: 255
 * Total Accepted:    1.7M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void findsubSetRec(int idx, const vector<int> & nums){

        if(idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        findsubSetRec(idx + 1, nums);
        subset.pop_back();
        findsubSetRec(idx + 1, nums);
    }

    void findsubSetBt(int idx, const vector<int> & nums){
        ans.push_back(subset);

        for(int i = idx; i < nums.size(); i++){
            subset.push_back(nums[i]);
            findsubSetBt(i + 1, nums);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        findsubSetBt(0, nums);
        return ans;
    }
};
// @lc code=end


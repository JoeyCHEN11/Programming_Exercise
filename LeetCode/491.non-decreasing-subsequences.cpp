/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 *
 * https://leetcode.com/problems/non-decreasing-subsequences/description/
 *
 * algorithms
 * Medium (60.55%)
 * Likes:    3581
 * Dislikes: 228
 * Total Accepted:    163.4K
 * Total Submissions: 269.9K
 * Testcase Example:  '[4,6,7,7]'
 *
 * Given an integer array nums, return all the different possible
 * non-decreasing subsequences of the given array with at least two elements.
 * You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,6,7,7]
 * Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,4,3,2,1]
 * Output: [[4,4]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 15
 * -100 <= nums[i] <= 100
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

    void findNdRec(int depth, const vector<int> & nums){
        if(depth == nums.size()){
            if(subset.size() >= 2) ans.emplace_back(subset);
            return;
        }

        if(subset.empty() || nums[depth] >= subset.back()){
            subset.push_back(nums[depth]);
            findNdRec(depth + 1, nums);
            subset.pop_back();
        }

        //break the searching when last chosen equals current
        //that is, when the last and current are same, remove "pick last, do not pick current" case,reserve other 3 cases
        if(subset.empty() || nums[depth] != subset.back()){
            findNdRec(depth + 1, nums);
        }

    }

    void findNdSubsequence(int idx, const vector<int>& nums){
        if(subset.size() > 1) ans.emplace_back(subset);

        unordered_set<int> s;
        //bool check[201] {false};
        for(int i = idx; i < nums.size(); i ++){
            if((subset.empty() || subset.back() <= nums[i]) && s.find(nums[i]) == s.end()){
                subset.emplace_back(nums[i]);
                s.insert(nums[i]);
                findNdSubsequence(i + 1, nums);
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        findNdRec(0, nums);
        return ans;
    }
};
// @lc code=end


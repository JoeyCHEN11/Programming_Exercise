/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.87%)
 * Likes:    18556
 * Dislikes: 311
 * Total Accepted:    2M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> permutation;
    vector<vector<int>> ans;
    unordered_set<int> check;
    
    void findPermutation(int depth,const vector<int>& nums){
        if(depth == nums.size()){
            ans.emplace_back(permutation);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(check.find(nums[i]) == check.end()){
                check.insert(nums[i]);
                permutation[depth] = nums[i];
                findPermutation(depth + 1, nums);
                check.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permutation.resize(nums.size());

        findPermutation(0, nums);

        return ans;
    }
};
// @lc code=end


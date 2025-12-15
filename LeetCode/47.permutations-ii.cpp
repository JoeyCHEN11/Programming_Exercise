/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (58.67%)
 * Likes:    8346
 * Dislikes: 139
 * Total Accepted:    887.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
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
    vector<bool> totalCheck;

    void findPermutation(int depth,const vector<int>& nums){
        if(depth == nums.size()){
            ans.emplace_back(permutation);
            return;
        }

        unordered_set<int> localCheck;
        for(int i = 0; i < nums.size(); i++){
            if(!totalCheck[i] && localCheck.find(nums[i]) == localCheck.end()){
                totalCheck[i] = true;
                localCheck.insert(nums[i]);
                permutation[depth] = nums[i];
                findPermutation(depth + 1, nums);
                totalCheck[i] = false;
            }
        }
    }

    void findPermutationSort(int depth, const vector<int> & nums){
        if(depth == nums.size()){
            ans.emplace_back(permutation);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            
            if(totalCheck[i]) continue;

            //                                     totalCheck[i - 1] == true ok, but slower
            //                                     (↑ omit permutations start with p[a_pos_before] = "same previous element")
            //                                     (↓ omit permutations start with p[depth] = "same current element")
            if(i > 0 && nums[i] == nums[i - 1] && !totalCheck[i - 1]) continue;

            totalCheck[i] = true;
            permutation[depth] = nums[i];
            findPermutationSort(depth + 1, nums);
            totalCheck[i] = false;
        }

    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        totalCheck.resize(nums.size(), false);
        permutation.resize(nums.size());

        //findPermutation(0, nums);

        sort(nums.begin(), nums.end());
        findPermutationSort(0, nums);

        return ans;
    }
};
// @lc code=end


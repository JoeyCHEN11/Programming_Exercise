/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (54.11%)
 * Likes:    10135
 * Dislikes: 280
 * Total Accepted:    910.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> subcomb;
    vector<vector<int>> ans;

    //find all combinations sum up to target, which start from candidate[idx]
    void findComb(int idx, int target, vector<int> & candidates){
        if(target == 0){
            ans.emplace_back(subcomb);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(target < candidates[i]) return;
            //omit repeat combinations
            if(i > idx && candidates[i] == candidates[i - 1]) continue;
            subcomb.emplace_back(candidates[i]);
            findComb(i + 1, target - candidates[i], candidates);
            subcomb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        findComb(0, target, candidates);
        return ans;
    }
};
// @lc code=end


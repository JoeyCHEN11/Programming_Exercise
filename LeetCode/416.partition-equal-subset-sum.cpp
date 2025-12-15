/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (46.22%)
 * Likes:    11952
 * Dislikes: 231
 * Total Accepted:    780K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given an integer array nums, return true if you can partition the array into
 * two subsets such that the sum of the elements in both subsets is equal or
 * false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        int n = nums.size(), s = sum/2;
        if(sum & 1 | maxNum > s) return false;
        if(maxNum == s) return true; 

        //DP-2D
        // vector<vector<bool>> canSum(n + 1, vector<bool>(s + 1, false));
        // for(int i = 0; i <= n; i++) canSum[i][0] = true;
        // for(int i = 1; i <= n; i++){
        //     for (int j = 1; j <= s; j++){
        //         if(j < nums[i - 1]) canSum[i][j] = canSum[i - 1][j];
        //         else canSum[i][j] = canSum[i - 1][j] | canSum[i - 1][j - nums[i - 1]];
        //     }
        //     if(canSum[i][s]) return true;
        // }

        //dp 1D
        vector<bool> canSum1D(s + 1, false);
        canSum1D[0] = true;
        for(int i = 0; i < n; i++){
            for (int j = s; j >= nums[i]; j--){
                canSum1D[j] = canSum1D[j] | canSum1D[j - nums[i]];
            }
            if(canSum1D[s]) return true;
        }

        return false;
    }
};
// @lc code=end


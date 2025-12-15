/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (34.99%)
 * Likes:    18152
 * Dislikes: 594
 * Total Accepted:    1.2M
 * Total Submissions: 3.5M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find a subarray that has the largest product,
 * and return the product.
 * 
 * The test cases are generated so that the answer will fit in a 32-bit
 * integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxP(n), minP(n);
        maxP[0] = minP[0] = nums[0];

        for(int i = 1; i < n; i++){
            maxP[i] = max(maxP[i - 1] * nums[i], max(minP[i - 1] * nums[i], nums[i]));
            minP[i] = min(minP[i - 1] * nums[i], min(maxP[i - 1] * nums[i], nums[i]));
            
        }
        return *max_element(maxP.begin(), maxP.end());
    }
};
// @lc code=end


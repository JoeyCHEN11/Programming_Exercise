/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 *
 * https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/
 *
 * algorithms
 * Easy (50.94%)
 * Likes:    1507
 * Dislikes: 111
 * Total Accepted:    85.4K
 * Total Submissions: 167.7K
 * Testcase Example:  '[4,2,3]\n1'
 *
 * Given an integer array nums and an integer k, modify the array in the
 * following way:
 * 
 * 
 * choose an index i and replace nums[i] with -nums[i].
 * 
 * 
 * You should apply this process exactly k times. You may choose the same index
 * i multiple times.
 * 
 * Return the largest possible sum of the array after modifying it in this
 * way.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,2,3], k = 1
 * Output: 5
 * Explanation: Choose index 1 and nums becomes [4,-2,3].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,-1,0,2], k = 3
 * Output: 6
 * Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,-3,-1,5,-4], k = 2
 * Output: 13
 * Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -100 <= nums[i] <= 100
 * 1 <= k <= 10^4
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        int ans = accumulate(nums.begin(), nums.end(), 0);

        //o(nlogn)
        // priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        // while(k--){
        //     int u = pq.top(); pq.pop();
        //     ans -= 2*u;
        //     pq.push(-u);
        // }
        
        //o(n + C)
        unordered_map<int, int> check;
        for(int num : nums) check[num]++;

        for(int i = -100; i < 0; i++){
            if(check[i]){
                int ops = min(k, check[i]);
                ans -= 2 * ops * i;
                check[i] -= ops;
                check[-i] += ops;
                k -= ops;
                if(!k) break;
            }
        }

        if(k > 0 && k % 2 == 1){
            for(int i = 0; i <= 100; i++){
                if(check[i]) {
                    ans -= 2 * i;
                    break;
                }
            }
        }

        return ans;
    }
};
// @lc code=end


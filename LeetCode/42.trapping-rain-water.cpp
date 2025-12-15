/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (60.47%)
 * Likes:    30317
 * Dislikes: 458
 * Total Accepted:    1.8M
 * Total Submissions: 3M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        stack<int> s;
 
        for(int i = 0; i < n; i++){
            int prev = 0;
            while(!s.empty() && height[s.top()] <= height[i]){
                int left = s.top(); s.pop();
                ans += (height[left] - prev) * (i - left - 1);
                prev = height[left];
            }
            if(!s.empty()) ans += (height[i] - prev) * (i - s.top() - 1);
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end


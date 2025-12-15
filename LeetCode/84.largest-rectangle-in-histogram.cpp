/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (44.12%)
 * Likes:    16700
 * Dislikes: 257
 * Total Accepted:    843.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given an array of integers heights representing the histogram's bar height
 * where the width of each bar is 1, return the area of the largest rectangle
 * in the histogram.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10
 * units.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: heights = [2,4]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= heights.length <= 10^5
 * 0 <= heights[i] <= 10^4
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxRec = 0;
        int n = heights.size();
        heights.push_back(0);
        stack<pair<int, int>> s;
        s.emplace(-1, 0);
        for(int i = 0; i <= n; i++){
            int newLeft = i;//更新新矩形的左边界
            while(heights[i] < s.top().second){
                auto [left, height] = s.top(); s.pop();
                maxRec = max(maxRec, (i - left) * height);
                newLeft = left;
            }
            if(heights[i] > s.top().second) s.emplace(newLeft, heights[i]);
        }

        return maxRec;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (46.94%)
 * Likes:    21648
 * Dislikes: 753
 * Total Accepted:    2.3M
 * Total Submissions: 4.8M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlap, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> & v1, const vector<int> & v2) -> bool { return v1[0] < v2[0];});

        //提前放入第一个区间
        vector<vector<int>> ans {{intervals[0][0], intervals[0][1]}};
        
        for(int i = 1; i < intervals.size(); i++){
            //直接在答案里修改右边界
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            //没有可合并的区间，即left > end时，添加新的区间
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;

    }
};
// @lc code=end


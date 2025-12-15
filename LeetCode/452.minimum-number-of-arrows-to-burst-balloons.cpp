/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (56.07%)
 * Likes:    6712
 * Dislikes: 199
 * Total Accepted:    377.4K
 * Total Submissions: 672K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are some spherical balloons taped onto a flat wall that represents the
 * XY-plane. The balloons are represented as a 2D integer array points where
 * points[i] = [xstart, xend] denotes a balloon whose horizontal diameter
 * stretches between xstart and xend. You do not know the exact y-coordinates
 * of the balloons.
 * 
 * Arrows can be shot up directly vertically (in the positive y-direction) from
 * different points along the x-axis. A balloon with xstart and xend is burst
 * by an arrow shot at x if xstart <= x <= xend. There is no limit to the
 * number of arrows that can be shot. A shot arrow keeps traveling up
 * infinitely, bursting any balloons in its path.
 * 
 * Given the array points, return the minimum number of arrows that must be
 * shot to burst all balloons.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[10,16],[2,8],[1,6],[7,12]]
 * Output: 2
 * Explanation: The balloons can be burst by 2 arrows:
 * - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
 * - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[1,2],[3,4],[5,6],[7,8]]
 * Output: 4
 * Explanation: One arrow needs to be shot for each balloon for a total of 4
 * arrows.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: points = [[1,2],[2,3],[3,4],[4,5]]
 * Output: 2
 * Explanation: The balloons can be burst by 2 arrows:
 * - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
 * - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= points.length <= 10^5
 * points[i].length == 2
 * -2^31 <= xstart < xend <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    static bool compX(const vector<int> & b1, const vector<int> & b2){ return b1[0] < b2[0];}
    static bool compY(const vector<int> & b1, const vector<int> & b2){ return b1[1] < b2[1];}
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        
        int ans = 1;
        int end;

        //shoot ballon from which has minumum start, update minimum end(right) untill we need another arrow
        // sort(points.begin(), points.end(), compX);
        // end = points[0][1];
        // for(auto & balloon : points){
        //     //check start: if next balloon is out of this range, use next arrow
        //     if(balloon[0] > end) {
        //         ans++;
        //         end = balloon[1];
        //     }
        //     //if there is another balloon shot, check end: update the minimum end (right bound);
        //     else if(balloon[1] < end) end = balloon[1];
        // }


        sort(points.begin(), points.end(), compY);
        end = points[0][1];
        for(auto& balloon : points){
            if(balloon[0] > end){
                ans++;
                end = balloon[1];
            }
        }

        


        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 *
 * https://leetcode.com/problems/last-stone-weight-ii/description/
 *
 * algorithms
 * Medium (54.97%)
 * Likes:    3024
 * Dislikes: 109
 * Total Accepted:    83.5K
 * Total Submissions: 151.8K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * You are given an array of integers stones where stones[i] is the weight of
 * the i^th stone.
 * 
 * We are playing a game with the stones. On each turn, we choose any two
 * stones and smash them together. Suppose the stones have weights x and y with
 * x <= y. The result of this smash is:
 * 
 * 
 * If x == y, both stones are destroyed, and
 * If x != y, the stone of weight x is destroyed, and the stone of weight y has
 * new weight y - x.
 * 
 * 
 * At the end of the game, there is at most one stone left.
 * 
 * Return the smallest possible weight of the left stone. If there are no
 * stones left, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: stones = [2,7,4,1,8,1]
 * Output: 1
 * Explanation:
 * We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
 * we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
 * we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
 * we can combine 1 and 1 to get 0, so the array converts to [1], then that's
 * the optimal value.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: stones = [31,26,33,21,40]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 100
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int s = sum / 2;
        
        vector<bool> smashGroup(s + 1, false);
        smashGroup[0] = true;

        for(int i = 0; i < n; i++){
            for(int j = s; j >= stones[i]; j--){
                smashGroup[j] = smashGroup[j] | smashGroup[j - stones[i]];
            }
        }
        
        for(int i = s; i >= 0; i--) if(smashGroup[i]) return sum - 2 * i;

        return -1;

    }
};
// @lc code=end


/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (43.23%)
 * Likes:    7511
 * Dislikes: 612
 * Total Accepted:    478.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,0,2]'
 *
 * There are n children standing in a line. Each child is assigned a rating
 * value given in the integer array ratings.
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * Return the minimum number of candies you need to have to distribute the
 * candies to the children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ratings = [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ratings = [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * The third child gets 1 candy because it satisfies the above two
 * conditions.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == ratings.length
 * 1 <= n <= 2 * 10^4
 * 0 <= ratings[i] <= 2 * 10^4
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;

        // //O(n) space，当需要关注左右的大小情况，可以从两个方向分别遍历，然后取都满足条件的数
        // vector<int> candies(n, 1);
        // //检查所有比左边rating大的孩子
        // for(int i = 1; i < n; i++){
        //     if(ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        // }
        // //检查所有比右边rating大的孩子
        // for(int i = n - 2; i >= 0; i--){
        //     if(ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
        // }
        // ans = accumulate(candies.begin(), candies.end(), 0);

        //O(1) space
        //上一个孩子的糖果数量
        int prev = 1;
        //dec:当其值小于上一个递增序列inc的长度时，为不算第一个最大数的连续递减子数组的长度
        //    当其值大于等于上一个递增序列的长度时，算入第一个最大数（因为此时，实际的递减序列长度比递增序列大，所以最大值的孩子需要跟随其递减序列获得糖果）
        //inc：算入最后一个最大值的连续递增子数组的长度，用于辅助dec计数
        int decLen = 0, incLen = 1;
        ans += 1;
        for(int i = 1; i < n; i++){
            if(ratings[i] >= ratings[i - 1]){
                //计算当前孩子糖果数量
                prev = ratings[i] == ratings[i - 1]? 1 : prev+1;
                ans += prev;
                incLen = prev;
                decLen = 0;
            }else{
                prev = 1;
                decLen++;
                
                if(decLen == incLen) decLen++;
                //每次递减时，根据递减序列长度，隐式地给前面的递减中的孩子都补一颗糖果
                ans += decLen;
            } 
        }

        return ans;
    }
};
// @lc code=end


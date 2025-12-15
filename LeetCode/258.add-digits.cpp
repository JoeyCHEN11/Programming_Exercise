/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (66.52%)
 * Likes:    4766
 * Dislikes: 1929
 * Total Accepted:    779.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '38'
 *
 * Given an integer num, repeatedly add all its digits until the result has
 * only one digit, and return it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = 38
 * Output: 2
 * Explanation: The process is
 * 38 --> 3 + 8 --> 11
 * 11 --> 1 + 1 --> 2 
 * Since 2 has only one digit, return it.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = 0
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= num <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you do it without any loop/recursion in O(1) runtime?
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        int ans = num;
        while(ans >= 10){
            int temp = ans;
            ans = 0;
            while(temp > 0){
                ans += temp % 10;
                temp /= 10;
            }
        }
        return ans;
    }
};
// @lc code=end


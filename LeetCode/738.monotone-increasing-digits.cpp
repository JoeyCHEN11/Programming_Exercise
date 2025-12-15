/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 *
 * https://leetcode.com/problems/monotone-increasing-digits/description/
 *
 * algorithms
 * Medium (47.77%)
 * Likes:    1289
 * Dislikes: 103
 * Total Accepted:    51K
 * Total Submissions: 106.6K
 * Testcase Example:  '10'
 *
 * An integer has monotone increasing digits if and only if each pair of
 * adjacent digits x and y satisfy x <= y.
 * 
 * Given an integer n, return the largest number that is less than or equal to
 * n with monotone increasing digits.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 10
 * Output: 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1234
 * Output: 1234
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 332
 * Output: 299
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 10^9
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string digits = to_string(n);

        int idx = 0;
        while(idx + 1 < digits.size() && digits[idx] <= digits[idx + 1]){
            idx++;
        }

        if(idx == digits.size() - 1) return n;
    
        
        while(idx - 1 >= 0 && digits[idx] == digits[idx - 1]){
            idx--;
        }
        digits[idx]--;
        
        idx++;
        while(idx < digits.size()){
            digits[idx] = '9';
            idx++;
        }

        return stoi(digits);
    }
};
// @lc code=end


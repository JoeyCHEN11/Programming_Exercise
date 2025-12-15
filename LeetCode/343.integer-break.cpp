/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (60.14%)
 * Likes:    5020
 * Dislikes: 440
 * Total Accepted:    347.4K
 * Total Submissions: 577.3K
 * Testcase Example:  '2'
 *
 * Given an integer n, break it into the sum of k positive integers, where k >=
 * 2, and maximize the product of those integers.
 * 
 * Return the maximum product you can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 58
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int integerBreak(int n) {
        vector<int> products(n + 1, 0);
        products[0] = products[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                products[i] = max(products[i], max(j * (i - j), j * products[i - j]));
            }
        }

        return products[n];
    }
};
// @lc code=end


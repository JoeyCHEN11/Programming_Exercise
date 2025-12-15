/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (53.15%)
 * Likes:    11033
 * Dislikes: 460
 * Total Accepted:    831.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '12'
 *
 * Given an integer n, return the least number of perfect square numbers that
 * sum to n.
 * 
 * A perfect square is an integer that is the square of an integer; in other
 * words, it is the product of some integer with itself. For example, 1, 4, 9,
 * and 16 are perfect squares while 3 and 11 are not.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int x){
        int sqx = sqrt(x);
        return sqx * sqx == x;
    }

    int numSquaresNumTheory(int n){
        
        if(isPerfectSquare(n)) return 1;

        int x = n;
        while(x % 4 == 0){
            x /= 4;
        }
        if(x % 8 == 7) return 4;

        for(int a = 1; a * a <= n; a++){
            if(isPerfectSquare(n - a * a)) return 2;
        }

        return 3;
    }

    int numSquares(int n) {
        // vector<int> dp(n + 1, n + 1);
        // dp[0] = 0;
        // for(int i = 1; i * i <= n; i++){
        //     for(int j = i * i; j <= n; j++){
        //         dp[j] = min(dp[j], dp[j - i * i] + 1);
        //     }
        // }

        // return dp[n];
        return numSquaresNumTheory(n);
    }
};
// @lc code=end


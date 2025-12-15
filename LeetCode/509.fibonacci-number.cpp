/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 *
 * https://leetcode.com/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (70.69%)
 * Likes:    7919
 * Dislikes: 348
 * Total Accepted:    1.7M
 * Total Submissions: 2.4M
 * Testcase Example:  '2'
 *
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
 * Fibonacci sequence, such that each number is the sum of the two preceding
 * ones, starting from 0 and 1. That is,
 * 
 * 
 * F(0) = 0, F(1) = 1
 * F(n) = F(n - 1) + F(n - 2), for n > 1.
 * 
 * 
 * Given n, calculate F(n).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 1
 * Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: 2
 * Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 4
 * Output: 3
 * Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //int fibDP[31] = {0};
    int fib(int n) {

        // fibDP[0] = 0;
        // fibDP[1] = 1;
        // for(int i = 2; i <= n; i++){
        //     fibDP[i] = fibDP[i - 1] + fibDP[i - 2];
        // }

        //optimized O(1) space
        if(n == 0) return 0;
        if(n == 1) return 1;
        int a = 0, b = 1, ans;
        for(int i = 2; i <= n; i++){
            ans = a + b;
            a = b;
            b = ans;
        }

        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (55.70%)
 * Likes:    9907
 * Dislikes: 1356
 * Total Accepted:    1.4M
 * Total Submissions: 2.4M
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number n is happy.
 * 
 * A happy number is a number defined by the following process:
 * 
 * 
 * Starting with any positive integer, replace the number by the sum of the
 * squares of its digits.
 * Repeat the process until the number equals 1 (where it will stay), or it
 * loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy.
 * 
 * 
 * Return true if n is a happy number, and false if not.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 19
 * Output: true
 * Explanation:
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start

#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> check;
        
        int new_n,k;
        while(n != 1){
            new_n = 0;
            while(n != 0){
                k = n % 10;
                new_n += k * k;
                n /= 10;
            }
            n = new_n;
            if(check.find(n)!=check.end()) return false;
            else check.insert(n);
        }
        return true;


        // unordered_set<int> check;
        // string n_str;
        // int new_n,k;
        // while(check.find(1)==check.end()){
        //     n_str = to_string(n);
        //     n = 0;
        //     for(char c : n_str){
        //         k = c - '0';
        //         n += k * k;
        //     }
        //     if(check.find(n)!=check.end()) return false;
        //     else check.insert(n);
        // }
        // return true;
    }
};
// @lc code=end


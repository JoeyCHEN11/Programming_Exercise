/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (53.14%)
 * Likes:    9173
 * Dislikes: 937
 * Total Accepted:    1.4M
 * Total Submissions: 2.6M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings a and b, return their sum as a binary string.
 * 
 * 
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) swap(a, b);
        int n = a.size();
        int offset = n - b.size();
        
        string c(n, '0');
        
        char carry = 0, ai, bi; 
        for(int i = n - 1; i >= 0; i--){
            ai = a[i] - '0'; 
            bi = i - offset >= 0 ? b[i - offset] - '0' : 0;
            c[i] = (ai ^ bi ^ carry) + '0';
            carry = ai & bi | ((ai | bi) & carry);
        }
        if(carry == 0) return c;
        else return '1' + c;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (40.27%)
 * Likes:    6947
 * Dislikes: 3281
 * Total Accepted:    781.4K
 * Total Submissions: 1.9M
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 * 
 * 
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    string multiplyOptimal(string & num1, string & num2) {
        if(num1.size() > num2.size()) swap(num1, num2);
        if(num1 == "0" || num2 == "0") return "0"; 

        int n1 = num1.size();
        int n2 = num2.size();
        int shift = 0;
        
        //统一按位乘法 + 移位加法，直接相加（无限进制）
        vector<int> ansArr(n1 + n2, 0);
        for(int i = n1 - 1; i >= 0; i--){
            int idx = shift;
            for(int j = n2 - 1; j >=0; j--){
                ansArr[idx] += (num2[j] - '0') * (num1[i] - '0');
                idx++;
            }
            shift++;
        }

        //remove leading zeros
        while(ansArr.back() == 0) ansArr.pop_back();

        //结果统一转十进制， 再转ascii
        int carry = 0;
        for_each(ansArr.begin(), ansArr.end(), 
        [&carry](int & digit) -> void{
            digit = carry + digit;
            carry = digit / 10;
            digit = (digit % 10) + '0';
        });
        if(carry) ansArr.push_back(carry + '0');

        return string(ansArr.rbegin(), ansArr.rend());
    }

    string multiply(string num1, string num2) {
        // if(num1.size() > num2.size()) swap(num1, num2);
        // if(num1 == "0" || num2 == "0") return "0"; 

        // int n1 = num1.size();
        // int n2 = num2.size();
        // int shift = 0, carry = 0, sumCarry = 0;
        // string ans(n1 + n2, '0');
        // for(int i = n1 - 1; i >= 0; i--){
        //     int idx = shift;
        //     carry = 0;
        //     sumCarry = 0;
        //     for(int j = n2 - 1; j >=0; j--){
        //         //cout<<"now: "<<num1[i]<<" * "<<num2[j]<<endl;
        //         //cout<<"sumC:"<<sumCarry<<endl;
        //         int mult = (num2[j] - '0') * (num1[i] - '0') + carry;
        //         int d = mult % 10;
        //         int s = (ans[idx] - '0') + d + sumCarry;
        //         ans[idx] = (s % 10) + '0';
        //         carry = mult / 10;
        //         sumCarry = s / 10;
        //         idx++;
        //         //cout<<ans<<endl;
        //     }
        //     ans[idx] += carry + sumCarry;
        //     shift++;
        // }
        // while(ans.back() == '0') ans.pop_back();
        // reverse(ans.begin(), ans.end());
        // return ans;

        return multiplyOptimal(num1, num2);
    }
};
// @lc code=end


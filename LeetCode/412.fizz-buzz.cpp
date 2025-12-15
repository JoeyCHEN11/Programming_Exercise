/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (71.98%)
 * Likes:    2670
 * Dislikes: 360
 * Total Accepted:    1.2M
 * Total Submissions: 1.7M
 * Testcase Example:  '3'
 *
 * Given an integer n, return a string array answer (1-indexed) where:
 * 
 * 
 * answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * answer[i] == "Fizz" if i is divisible by 3.
 * answer[i] == "Buzz" if i is divisible by 5.
 * answer[i] == i (as a string) if none of the above conditions are true.
 * 
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["1","2","Fizz"]
 * Example 2:
 * Input: n = 5
 * Output: ["1","2","Fizz","4","Buzz"]
 * Example 3:
 * Input: n = 15
 * Output:
 * ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        //brute force
        for(int i = 0; i < n; i++){
            if((i+1) % 5 == 0 && (i+1) % 3 == 0){
                ans[i] = "FizzBuzz";
            }else if((i + 1) % 5 == 0){
                ans[i] = "Buzz";
            }else if((i + 1) % 3 == 0){
                ans[i] = "Fizz";
            }else ans[i] = to_string(i + 1);
        }        
        return ans;

    }
};
// @lc code=end


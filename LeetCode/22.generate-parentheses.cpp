/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (74.32%)
 * Likes:    20615
 * Dislikes: 889
 * Total Accepted:    1.8M
 * Total Submissions: 2.4M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int cnt;
    vector<string> ans;
    string parenthesis;

    void rec(int depth, int n){
        if(depth >= 2 * n){
            if(cnt == 0) ans.emplace_back(parenthesis);
            return;
        }

        if(cnt < n){
            cnt++;
            parenthesis.push_back('(');
            rec(depth + 1, n);
            parenthesis.pop_back();
            cnt--;
        }

        if(cnt > 0){
            cnt--;
            parenthesis.push_back(')');
            rec(depth + 1, n);
            parenthesis.pop_back();
            cnt++;
        }

    }
    vector<string> generateParenthesis(int n) {
        cnt = 0;
        rec(0, n);
        return ans;
    }
};
// @lc code=end


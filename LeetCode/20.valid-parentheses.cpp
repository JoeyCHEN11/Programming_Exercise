/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.39%)
 * Likes:    23240
 * Dislikes: 1634
 * Total Accepted:    4.2M
 * Total Submissions: 10.5M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(char c : s){
            switch (c){
                case ']':
                    if(check.empty() || check.top() != '[') return false;
                    check.pop();
                    break;
                case ')':
                    if(check.empty() || check.top() != '(') return false;
                    check.pop();
                    break;
                case '}':
                    if(check.empty() || check.top() !=  '{') return false;
                    check.pop();
                    break;
                default:
                    check.push(c);
                    break;
            }
        }
        return check.empty();
    }
};
// @lc code=end


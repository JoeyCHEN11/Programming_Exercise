/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
 *
 * algorithms
 * Easy (69.23%)
 * Likes:    6416
 * Dislikes: 242
 * Total Accepted:    530.7K
 * Total Submissions: 766.3K
 * Testcase Example:  '"abbaca"'
 *
 * You are given a string s consisting of lowercase English letters. A
 * duplicate removal consists of choosing two adjacent and equal letters and
 * removing them.
 * 
 * We repeatedly make duplicate removals on s until we no longer can.
 * 
 * Return the final string after all such duplicate removals have been made. It
 * can be proven that the answer is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abbaca"
 * Output: "ca"
 * Explanation: 
 * For example, in "abbaca" we could remove "bb" since the letters are adjacent
 * and equal, and this is the only possible move.  The result of this move is
 * that the string is "aaca", of which only "aa" is possible, so the final
 * string is "ca".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "azxxzy"
 * Output: "ay"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        // stack<char> check;
        // string ans;
        // for(char c : s){
        //     if(check.empty() || check.top() != c) check.push(c);
        //     else check.pop();
        // }
        // while(!check.empty()){
        //     char c = check.top(); check.pop();
        //     ans.push_back(c);
        // }
        // reverse(ans.begin(), ans.end());

        
        string ans;
        for(char c : s){
            if(ans.empty() || ans.back() != c) ans.push_back(c);
            else ans.pop_back();
        }
        return ans;
    }
};
// @lc code=end


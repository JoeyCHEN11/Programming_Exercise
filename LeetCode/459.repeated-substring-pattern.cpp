/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (46.05%)
 * Likes:    6278
 * Dislikes: 507
 * Total Accepted:    429K
 * Total Submissions: 931.5K
 * Testcase Example:  '"abab"'
 *
 * Given a string s, check if it can be constructed by taking a substring of it
 * and appending multiple copies of the substring together.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abab"
 * Output: true
 * Explanation: It is the substring "ab" twice.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aba"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "abcabcabcabc"
 * Output: true
 * Explanation: It is the substring "abc" four times or the substring "abcabc"
 * twice.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next;
        build_next(next, s);
        int n = s.size();
        return next[n - 1] >=0 && n%(n - (next[n - 1]+1)) == 0;
    }
    //kmp build next
    void build_next(vector<int>& next, const string & s){
        int k = -1, n = s.size();
        next.resize(n);
        next[0] = -1;
        for(int i = 1; i < n; i++ ){
            while(k >= 0 && s[k+1] != s[i]){
                k = next[k];
            }
            if(s[k+1] == s[i]) k++;
            next[i] = k;
        }
        //for(int i:next) cout<<i<<" ";
    }
};
// @lc code=end


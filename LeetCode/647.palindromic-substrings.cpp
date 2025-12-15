/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647]    
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (69.96%)
 * Likes:    10606
 * Dislikes: 228
 * Total Accepted:    783K
 * Total Submissions: 1.1M
 * Testcase Example:  '"abc"'
 *
 * Given a string s, return the number of palindromic substrings in it.
 * 
 * A string is a palindrome when it reads the same backward as forward.
 * 
 * A substring is a contiguous sequence of characters within the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int manacher(string s){
            int cnt = 0;
            string manaS = "$#";
            for(const char & c : s){
                manaS += c;
                manaS += '#';
            }
            manaS += '@';
        
            int n = manaS.size();
            vector<int> f(n);
            int rMax = 0, iMax = 0;
            for(int i = 1; i < n; i++){
                int j = 2 * iMax - i;
                f[i] = i < rMax? min(rMax - i + 1, f[j]) : 1;
                
                while(manaS[i + f[i]] == manaS[i - f[i]]) f[i]++;

                if(i + f[i] - 1 > rMax){
                    rMax = i + f[i] - 1 ;
                    iMax = i;
                }
                cnt += f[i]/2;

            }
            return cnt;
    }

    int countSubstrings(string s) {
        // int cnt = 0;
        // int n = s.size();
        // vector<vector<bool>> dp(n, vector<bool>(n, false));

        // for (int length = 1; length <= n; length++){
        //     for (int i = 0; i < n - length + 1; i++){
        //         int j = i + length - 1;
        //         dp[i][j] = s[i] == s[j] && (i + 1 <= j - 1? dp[i + 1][j - 1] : true);
        //         if(dp[i][j]) cnt++;
        //     }
        // }
        return manacher(s);
    }
};
// @lc code=end


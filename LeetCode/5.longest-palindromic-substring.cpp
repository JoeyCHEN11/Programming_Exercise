/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (33.70%)
 * Likes:    28811
 * Dislikes: 1727
 * Total Accepted:    3M
 * Total Submissions: 8.8M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start

class Solution {
public:
    string manacher(const string & s){
        int maxP = 0, maxPi = 0;
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
            if(f[i] > maxP){
                maxP = f[i];
                maxPi = i;
            }

        }
        string ans;
        int left = maxPi - maxP + 1;
        int right = maxPi + maxP - 1;
        for(int i = manaS[left] == '#'? left + 1 : left; i <= right; i += 2){
            ans.push_back(manaS[i]);
        }
        return ans;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        //for(int i = 0; i < n; i++) dp[i][i] = true;

        int maxL = 1, maxI = 0;
        for(int len = 1; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                if(i + 1 <= j - 1) dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                else dp[i][j] = s[i] == s[j];

                if(dp[i][j] && len > maxL){
                    maxL = len;
                    maxI = i;
                }
            }
        }

        return s.substr(maxI, maxL);

        //return manacher(s);
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (46.54%)
 * Likes:    16824
 * Dislikes: 749
 * Total Accepted:    1.6M
 * Total Submissions: 3.5M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary
 * words.
 * 
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        // int m = wordDict.size();
        // vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        // dp[0][0] = true;
        // for(int j = 0; j <= n; j++){
        //     for (int i = 1; i <= m; i++){
        //         string word = wordDict[i - 1];
        //         if(word.size() > j) dp[i][j] = dp[i - 1][j];
        //         else dp[i][j] = dp[i - 1][j] | (dp[m][j - word.size()] & s.substr(j - word.size(), word.size()) == word);
        //     }
        // }
        // return dp[m][n];

        
        vector<bool> dp1D(n + 1, false);
        dp1D[0] = true;
        for(int i = 1; i <= n; i++){
            for(const string & word : wordDict){
                if(dp1D[i]) break;
                else if(word.size() > i) continue;
                else dp1D[i] = dp1D[i - word.size()] & s.substr(i - word.size(), word.size()) == word;
            }
        }
        return dp1D[n];
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (46.58%)
 * Likes:    6487
 * Dislikes: 287
 * Total Accepted:    380.1K
 * Total Submissions: 816.1K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given two strings s and t, return the number of distinct subsequences of s
 * which equals t.
 * 
 * The test cases are generated so that the answer fits on a 32-bit signed
 * integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "rabbbit", t = "rabbit"
 * Output: 3
 * Explanation:
 * As shown below, there are 3 ways you can generate "rabbit" from s.
 * rabbbit
 * rabbbit
 * rabbbit
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "babgbag", t = "bag"
 * Output: 5
 * Explanation:
 * As shown below, there are 5 ways you can generate "bag" from s.
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 1000
 * s and t consist of English letters.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        using ull = unsigned long long;
        int m = s.size(), n = t.size();
        vector<vector<ull>> dp(m + 1, vector<ull>(n + 1));
        for(vector<ull> & v : dp) v[0] = 1;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i - 1][j];
                if(s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end


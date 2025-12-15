/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (66.98%)
 * Likes:    12182
 * Dislikes: 416
 * Total Accepted:    760.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 * 
 * 
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool>> isPalindrome;

    vector<string> subPartition;
    vector<vector<string>> ans;

    /**
     * @brief build check table isPalindrome with DP
     * 
     * @param s target string
     * @param isPalindromeDP isPalindromeDP[i][j] : true if the substring s[i,j] (inclusive) is a palindrome
     */
    void buildPalindromeDP(const string& s,vector<vector<bool>>& isPalindromeDP){
        int n = s.size();
        isPalindromeDP.resize(s.size(), vector<bool>(s.size(), false));
        for (int length = 1; length <= n; length++){
            for (int i = 0; i < n - length + 1; i++){
                int j = i + length - 1;
                isPalindromeDP[i][j] = s[i] == s[j] && (i + 1 <= j - 1? isPalindromeDP[i + 1][j - 1] : true);
            }
        }
    }

    //find all possible palindrome partition
    void findPartition(int idx, const string & s){
        if(idx == s.size()){
            ans.emplace_back(subPartition);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(!isPalindrome[idx][i]) continue;
            subPartition.emplace_back(s.substr(idx, i - idx + 1));
            findPartition(i + 1, s);
            subPartition.pop_back();
        }

    }


    vector<vector<string>> partition(string s) {
        buildPalindromeDP(s, isPalindrome);
        findPartition(0, s);
        return ans;
    }
};
// @lc code=end


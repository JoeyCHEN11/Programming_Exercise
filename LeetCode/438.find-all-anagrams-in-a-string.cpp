/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (50.80%)
 * Likes:    12171
 * Dislikes: 336
 * Total Accepted:    856.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagramsElgant(const string & s, const string & p){
        vector<int> ans;
        int n = s.size(), m = p.size();
        vector<int> checkp(26, 0);
        for(char c : p) {
            checkp[c - 'a']++;
        }

        for(int left = 0, right = 0; right < n; right++){

            checkp[s[right] - 'a']--;

            //窗口条件：所有统计字母都不能小于0
            while(checkp[s[right] - 'a'] < 0){
                checkp[s[left] - 'a']++;
                left++;
            }

            if(right - left + 1 == m) ans.push_back(left);
        }
        return ans;
    }
    
    vector<int> findAnagrams(string s, string p) {
        // if(p.size() > s.size()) return {};

        // vector<int> ans;
        // //统计：有几种不同字母
        // int INF = 3e4 + 1;
        // int cnt = 0;
        // int n = s.size(), m = p.size();
        // vector<int> checkp(26, INF);

        // for(char c : p) {
        //     if(checkp[c - 'a'] == INF){
        //         checkp[c - 'a'] = 0;
        //         cnt++;
        //     }
        //     checkp[c - 'a']++;
        // }

        // for(int i = 0; i < n; i++){
        //     if(i >= m){
        //         if(checkp[s[i - m] - 'a'] != INF){
        //             if(!checkp[s[i - m] - 'a']) cnt++;
        //             checkp[s[i - m] - 'a']++;
        //         }
        //     }
        //     if(checkp[s[i] - 'a'] != INF){
        //         checkp[s[i] - 'a']--;
        //         if(!checkp[s[i] - 'a']) cnt--;
        //     }
        //     if(!cnt) ans.push_back(i - m + 1);
        // }
        
        // return ans;

        return findAnagramsElgant(s, p);
    }
};
// @lc code=end


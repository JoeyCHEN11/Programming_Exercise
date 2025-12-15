/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 *
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Easy (41.60%)
 * Likes:    5404
 * Dislikes: 351
 * Total Accepted:    2.2M
 * Total Submissions: 5.4M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * Given two strings needle and haystack, return the index of the first
 * occurrence of needle in haystack, or -1 if needle is not part of
 * haystack.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6.
 * The first occurrence is at index 0, so we return 0.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" did not occur in "leetcode", so we return -1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack and needle consist of only lowercase English characters.
 * 
 * 
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next;
        build_next(next, needle);
        
        int k = -1, n = haystack.size();
        for(int i = 0; i < n; i++){
            while(k >= 0 && needle[k+1] != haystack[i]){
                k = next[k];
            }
            if(needle[k+1] == haystack[i]) k++;
            if(k == needle.size() - 1) return i - k; 
        }
        return -1;
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


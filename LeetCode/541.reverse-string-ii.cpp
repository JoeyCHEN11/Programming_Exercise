/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (50.55%)
 * Likes:    1886
 * Dislikes: 3673
 * Total Accepted:    230.8K
 * Total Submissions: 456.5K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * Given a string s and an integer k, reverse the first k characters for every
 * 2k characters counting from the start of the string.
 * 
 * If there are fewer than k characters left, reverse all of them. If there are
 * less than 2k but greater than or equal to k characters, then reverse the
 * first k characters and leave the other as original.
 * 
 * 
 * Example 1:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * Example 2:
 * Input: s = "abcd", k = 2
 * Output: "bacd"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of only lowercase English letters.
 * 1 <= k <= 10^4
 * 
 * 
 */

// @lc code=start
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0 ; i < n; i += 2*k){
            int left = i, right = min(n, i + k);
            reverse(s.begin() + left,s.begin() + right);     
            // while(right > left) {
            //     swap(s[left], s[right]);
            //     right--; left++;
            // }
            
        }
        return s;
    }
    
};
// @lc code=end


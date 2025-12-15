/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (40.09%)
 * Likes:    7938
 * Dislikes: 5038
 * Total Accepted:    1.3M
 * Total Submissions: 3.3M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 * 
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 * 
 * Return a string of the words in reverse order concatenated by a single
 * space.
 * 
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 * 
 * 
 * 
 * Follow-up: If the string data type is mutable in your language, can you
 * solve it in-place with O(1) extra space?
 * 
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        //O(n) space
        // string ans;
        // vector<string> words;
        // s.push_back(' ');
        // int n = s.size();
        // for(int i = 0, j = 0; i < n; i = ++j){
        //     if(s[i] != ' '){
        //         j = i + 1;
        //         while(s[j] != ' ') j++;
        //         words.push_back(s.substr(i, j - i));
        //     }
        // }
        
        // for(int i = words.size() - 1; i >= 0; i--){
        //     ans += i? words[i] + " " : words[i];
        // }

        //return ans;

        //O(1) space
        //remove spaces
        int n = s.size();
        int slow = 0, fast = 0;
        while(fast < n && s[fast] == ' ') fast++;
        while(fast < n){
            if(!(fast > 0 && s[fast] == ' ' && s[fast-1] == ' ')) s[slow++] = s[fast];
            fast++;
        }
        s.resize(slow > 0 && s[slow-1] == ' '? slow - 1 : slow);

        //reverse string entirely
        n = s.size();
        reverse(s.begin(), s.end());

        //reverse every words
        for(int i = 0, j = 0; j<=n; j++){
            if(j == n || s[j] == ' ' ) {
                reverse(s.begin() + i, s.begin() + j);
                i = j+1;
            }
        }

        return s;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (59.73%)
 * Likes:    17945
 * Dislikes: 955
 * Total Accepted:    1.9M
 * Total Submissions: 3.2M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string numbers;
    string subcomb;
    vector<string> ans;
    
    vector<string> alphabet{"", "", "abc", 
                            "def", "ghi", "jkl", 
                            "mno", "pqrs", "tuv", 
                            "wxyz"};

    void rec(int idx){
        if(idx == numbers.size()) {
            ans.emplace_back(subcomb);
            return;
        }

        int digit = numbers[idx] - '0';
        int offset;
        if(digit <= 7){
            offset = 3 * (digit - 2);
        }else offset = 3 * (digit - 3) + 4;
        for(int i = 0; i < (digit == 7 || digit == 9? 4 : 3); i++){
            subcomb.push_back('a' + offset + i);
            rec(idx + 1);
            subcomb.pop_back();
        }
    }

    void recMap(int idx){
        if(idx == numbers.size()) {
            ans.emplace_back(subcomb);
            return;
        }

        int digit = numbers[idx] - '0';
        for(int i = 0; i < alphabet[digit].size(); i++){
            subcomb.push_back(alphabet[digit][i]);
            recMap(idx + 1);
            subcomb.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        numbers = digits;
        if(!digits.empty()) recMap(0);
        return ans;
    }
};
// @lc code=end


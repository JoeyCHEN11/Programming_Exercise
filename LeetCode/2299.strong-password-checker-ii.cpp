/*
 * @lc app=leetcode id=2299 lang=cpp
 *
 * [2299] Strong Password Checker II
 *
 * https://leetcode.com/problems/strong-password-checker-ii/description/
 *
 * algorithms
 * Easy (54.80%)
 * Likes:    338
 * Dislikes: 40
 * Total Accepted:    40K
 * Total Submissions: 73K
 * Testcase Example:  '"IloveLe3tcode!"'
 *
 * A password is said to be strong if it satisfies all the following
 * criteria:
 * 
 * 
 * It has at least 8 characters.
 * It contains at least one lowercase letter.
 * It contains at least one uppercase letter.
 * It contains at least one digit.
 * It contains at least one special character. The special characters are the
 * characters in the following string: "!@#$%^&*()-+".
 * It does not contain 2 of the same character in adjacent positions (i.e.,
 * "aab" violates this condition, but "aba" does not).
 * 
 * 
 * Given a string password, return true if it is a strong password. Otherwise,
 * return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: password = "IloveLe3tcode!"
 * Output: true
 * Explanation: The password meets all the requirements. Therefore, we return
 * true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: password = "Me+You--IsMyDream"
 * Output: false
 * Explanation: The password does not contain a digit and also contains 2 of
 * the same character in adjacent positions. Therefore, we return false.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: password = "1aB!"
 * Output: false
 * Explanation: The password does not meet the length requirement. Therefore,
 * we return false.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= password.length <= 100
 * password consists of letters, digits, and special characters:
 * "!@#$%^&*()-+".
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if(n < 8) return false;
        unordered_set<char> spCheck {'!','@','#','$','%','^','&','*','(',')','-','+'};
        bool lower = islower(password[0]), 
            upper = isupper(password[0]),
            digit = isdigit(password[0]),
            special = spCheck.count(password[0]);
        for(int i = 1; i < n; i++){
            if(password[i] == password[i - 1]) return false;

            lower = lower || islower(password[i]);
            upper = upper || isupper(password[i]),
            digit = digit || isdigit(password[i]),
            special = special || spCheck.count(password[i]);
        }
        return lower && upper && digit && special;
    }
};
// @lc code=end


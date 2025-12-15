/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (49.25%)
 * Likes:    5089
 * Dislikes: 777
 * Total Accepted:    441.5K
 * Total Submissions: 894.9K
 * Testcase Example:  '"25525511135"'
 *
 * A valid IP address consists of exactly four integers separated by single
 * dots. Each integer is between 0 and 255 (inclusive) and cannot have leading
 * zeros.
 * 
 * 
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP
 * addresses.
 * 
 * 
 * Given a string s containing only digits, return all possible valid IP
 * addresses that can be formed by inserting dots into s. You are not allowed
 * to reorder or remove any digits in s. You may return the valid IP addresses
 * in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 20
 * s consists of digits only.
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int SEG_COUNT = 4;
    vector<int> validIP;
    vector<string> ans;

    void findIP(int idx, int segIdx, const string& s){
        if(segIdx == SEG_COUNT){
            if(idx >= s.size()){
                string ipStr;
                for(int i = 0; i < SEG_COUNT; i++){
                    ipStr += to_string(validIP[i]);
                    if(i != SEG_COUNT - 1) ipStr += ".";
                }
                ans.emplace_back(ipStr);
            }
            return;
        }

        int octet = 0;
        //no need for i 0...3 because return automatically when octet > 255
        for (int i = idx; i < s.size(); i++){
            if(i > idx && s[idx] == '0') return;
            octet = octet * 10 + s[i] - '0';
            if(octet > 0xFF) return;
            validIP[segIdx] = octet;
            findIP(i + 1, segIdx + 1, s);
        }
        
    }

    vector<string> restoreIpAddresses(string s) {
        validIP.resize(SEG_COUNT);
        findIP(0, 0, s);
        return ans;
    }
};
// @lc code=end


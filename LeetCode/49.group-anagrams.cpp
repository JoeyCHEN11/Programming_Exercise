/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (68.32%)
 * Likes:    18754
 * Dislikes: 589
 * Total Accepted:    2.7M
 * Total Submissions: 4M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 * 
 * 
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:

    vector<vector<string>> groupAnagramsCnt(vector<string>& strs) {
        auto vecHash = [func = hash<int>{}](const vector<int>& vec) -> int {
            return accumulate(vec.begin(), vec.end(), 0, [&func](int acc, int num) -> int {
                return (acc << 1) ^ func(num);
            });
        };

        unordered_map<vector<int>, int, decltype(vecHash)> checkList(0, vecHash);
        vector<vector<string>> ans;
        int num = 0;
        for(const string& s : strs){    
            vector<int> key (26, 0);
            for(char c : s) key[c - 'a']++;

            if(checkList.find(key) != checkList.end()){
                ans[checkList[key]].emplace_back(s);
            }else {
                checkList[key] = num;
                num++;
                ans.push_back({s});
            }
        }
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> checkList;
        vector<vector<string>> ans;
        int num = 0;
        for(const string& s : strs){
            string key = s;
            sort(key.begin(),key.end());
            
            if(checkList.find(key) != checkList.end()){
                ans[checkList[key]].emplace_back(s);
            }else {
                checkList[key] = num;
                num++;
                ans.push_back({s});
            }
        }
        return ans;

        //return groupAnagramsCnt(strs);
    }
};
// @lc code=end


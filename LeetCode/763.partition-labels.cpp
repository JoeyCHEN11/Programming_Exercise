/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (79.80%)
 * Likes:    10142
 * Dislikes: 378
 * Total Accepted:    517.5K
 * Total Submissions: 648.5K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * You are given a string s. We want to partition the string into as many parts
 * as possible so that each letter appears in at most one part.
 * 
 * Note that the partition is done so that after concatenating all the parts in
 * order, the resultant string should be s.
 * 
 * Return a list of integers representing the size of these parts.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits s into less parts.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "eccbbbbdec"
 * Output: [10]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> check;
        int n = s.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            check[s[i]] = i;
        }

        int start = -1;
        int end = 0;
        for(int i = 0; i < n; i++){
            //update max end to promise that each letter appears in at most one part
            end = max(end, check[s[i]]);
            if(i == end){
                ans.push_back(end - start);
                start = end;
            }
        }
        
        return ans;
    }
};
// @lc code=end


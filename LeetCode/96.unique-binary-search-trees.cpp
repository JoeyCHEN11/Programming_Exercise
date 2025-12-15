/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (60.75%)
 * Likes:    10183
 * Dislikes: 395
 * Total Accepted:    641.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of structurally unique BST's (binary
 * search trees) which has exactly n nodes of unique values from 1 to n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 19
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> treeNum(n + 1);
        treeNum[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int r = 1; r <= i; r++){
                treeNum[i] += treeNum[r - 1] * treeNum[i - r];
            }
        }

        return treeNum[n];
    }
};
// @lc code=end


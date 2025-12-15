/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (69.91%)
 * Likes:    8036
 * Dislikes: 213
 * Total Accepted:    855.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 * 
 * You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, k = 2
 * Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * Explanation: There are 4 choose 2 = 6 total combinations.
 * Note that combinations are unordered, i.e., [1,2] and [2,1] are considered
 * to be the same combination.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, k = 1
 * Output: [[1]]
 * Explanation: There is 1 choose 1 = 1 total combination.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 1 <= k <= n
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int K, N;
    vector<int> subcomb;
    vector<vector<int>> ans;
public:
    void rec(int depth){
        if(subcomb.size() == K) {
            ans.emplace_back(subcomb);
            return;
        }

        if(K - subcomb.size() > N - depth + 1) return;

        subcomb.emplace_back(depth);
        rec(depth + 1);
        subcomb.pop_back();
        rec(depth + 1);
    }

    void backTracking(int depth){
        if(subcomb.size() == K){
            ans.emplace_back(subcomb);
            return;
        }

        //if(depth > N) return;
        
        for (int i = depth; i <= N - (K - subcomb.size()) + 1; i++){
            subcomb.emplace_back(i);
            backTracking(i + 1);
            subcomb.pop_back();
        }
        
    }


    vector<vector<int>> combine(int n, int k) {
        N = n;
        K = k;
        // rec(1);
        backTracking(1);
        return ans;
    }
};
// @lc code=end


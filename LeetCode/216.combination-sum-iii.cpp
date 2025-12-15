/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (69.20%)
 * Likes:    5783
 * Dislikes: 105
 * Total Accepted:    482K
 * Total Submissions: 696K
 * Testcase Example:  '3\n7'
 *
 * Find all valid combinations of k numbers that sum up to n such that the
 * following conditions are true:
 * 
 * 
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 * 
 * 
 * Return a list of all possible valid combinations. The list must not contain
 * the same combination twice, and the combinations may be returned in any
 * order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Explanation:
 * 1 + 2 + 4 = 7
 * There are no other valid combinations.
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6],[1,3,5],[2,3,4]]
 * Explanation:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * There are no other valid combinations.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: k = 4, n = 1
 * Output: []
 * Explanation: There are no valid combinations.
 * Using 4 different numbers in the range [1,9], the smallest sum we can get is
 * 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= k <= 9
 * 1 <= n <= 60
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> subSolution;
    vector<vector<int>> ans;
    int MAXN = 9;
    int K;
    void findCombRec(int depth, int n){
        if(n == 0 && subSolution.size() == K){
            ans.emplace_back(subSolution);
            return;
        }

        if(depth > n || depth > MAXN) return;
         

        subSolution.emplace_back(depth);
        findCombRec(depth + 1, n - depth);
        subSolution.pop_back();
        findCombRec(depth + 1, n);
    }

    void findCombBT(int start, int n){
        // optimize
        //if(n < 0) return;

        if(n == 0 && subSolution.size() == K){
            ans.emplace_back(subSolution);
            return;
        }
        
        //                      optimize (subcomb num)
        for (int i = start; i <= MAXN - (K - subSolution.size()) + 1; i++){
            //optimize before recursion;
            if(n - i < 0) return;
            subSolution.emplace_back(i);
            findCombBT(i + 1, n - i);
            subSolution.pop_back();
            /* code */
        }
        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        K = k;
        findCombBT(1, n);
        return ans;     
    }
};
// @lc code=end


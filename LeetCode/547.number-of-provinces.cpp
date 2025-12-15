/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (65.98%)
 * Likes:    9466
 * Dislikes: 349
 * Total Accepted:    852.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 * 
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 * 
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 * 
 * Return the total number of provinces.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int n;
    int cnt;
    vector<int> province;
    void bfs(int r, vector<vector<int>> & isConnected){
        province[r] = cnt;
        queue<int> que;
        que.emplace(r);

        while(!que.empty()){
            int u = que.front(); que.pop();

            for(int v = 0; v < n; v++){
                if(isConnected[u][v] && !province[v]){
                    que.emplace(v);
                    province[v] = cnt;
                }
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        province.resize(n, 0);
        cnt = 0;

        for(int i = 0; i < n; i++){
            if(!province[i]) {
                cnt++;
                bfs(i, isConnected);
            }
        }

        return cnt;

    }
};
// @lc code=end


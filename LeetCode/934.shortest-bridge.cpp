/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (57.68%)
 * Likes:    5304
 * Dislikes: 206
 * Total Accepted:    201.3K
 * Total Submissions: 349K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * You are given an n x n binary matrix grid where 1 represents land and 0
 * represents water.
 * 
 * An island is a 4-directionally connected group of 1's not connected to any
 * other 1's. There are exactly two islands in grid.
 * 
 * You may change 0's to 1's to connect the two islands to form one island.
 * 
 * Return the smallest number of 0's you must flip to connect the two
 * islands.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,1],[1,0]]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length == grid[i].length
 * 2 <= n <= 100
 * grid[i][j] is either 0 or 1.
 * There are exactly two islands in grid.
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int n;

    int dir[4][2] { -1, 0, 0, 1, 1, 0, 0, -1};
    bool boundCheck(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    void markLand(vector<vector<int>>& grid, int ri, int rj, int color){
        queue<pair<int, int>> que;
        que.emplace(ri, rj);
        grid[ri][rj] = color;

        while(!que.empty()){
            auto [ui, uj] = que.front(); que.pop();

            for(auto [dx, dy] : dir){
                int vi = ui + dx;
                int vj = uj + dy;
                if(boundCheck(vi, vj) && grid[vi][vj] == 1){
                    grid[vi][vj] = color;
                    que.emplace(vi, vj);
                }
            }
        }
    }

    int buildBridge(vector<vector<int>> & grid, queue<pair<int, int>> que, int target){
        int len = 1;

        while(!que.empty()){
            auto [ui, uj] = que.front(); que.pop();

            for(auto [dx, dy] : dir){
                int vi = ui + dx;
                int vj = uj + dy;
                if(boundCheck(vi, vj)){
                    if(grid[vi][vj] == target) return grid[ui][uj];
                    else if(grid[vi][vj] == 0){
                        grid[vi][vj] = grid[ui][uj] + 1;
                        que.emplace(vi, vj);
                    }
                }
            }
        }
        return -1;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        // bfs check
        n = grid.size();
        int color = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) markLand(grid, i, j, --color);
            }
        }
        
        queue<pair<int, int>> bridgeQue;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) {
                    for(auto [dx, dy] : dir){
                        int vi = i + dx, vj = j + dy;
                        if(boundCheck(vi, vj) && grid[vi][vj] == -1){
                            bridgeQue.emplace(i, j);
                            grid[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }

        return buildBridge(grid, bridgeQue, color);
    }
};
// @lc code=end


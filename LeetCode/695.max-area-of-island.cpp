/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (71.90%)
 * Likes:    9791
 * Dislikes: 198
 * Total Accepted:    832.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid. An island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * The area of an island is the number of cells with a value 1 in the island.
 * 
 * Return the maximum area of an island in grid. If there is no island, return
 * 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid =
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Output: 6
 * Explanation: The answer is not 11, because the island must be connected
 * 4-directionally.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,0,0,0,0,0,0,0]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] is either 0 or 1.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int m, n;
    int maxArea = 0;

    vector<vector<int>> next;
    vector<vector<bool>> visited;
    
    int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    bool available(int i, int j, const vector<vector<int>>& grid){
        return (i >=0 && i < m && j >= 0 && j <n && grid[i][j] == 1 && !visited[i][j]);
    }

    int bfs(int ri, int rj, vector<vector<int>>& grid){
        int area = 1;
        queue<pair<int, int>> bfsQ;
        bfsQ.emplace(ri, rj);
        visited[ri][rj] = true;
        
        while(!bfsQ.empty()){
            auto [ui, uj] = bfsQ.front(); bfsQ.pop();

            for(auto [iDir, jDir] : dir){
                int vi = ui + iDir;
                int vj = uj + jDir;
                if(available(vi, vj, grid)){
                    area++;
                    visited[vi][vj] = true;
                    bfsQ.emplace(vi, vj);
                }
            }
        }
        return area;
    }

    int findNext(int i, int j){
        return next[i][j] < 4? next[i][j]++ : -1;
    }
    int dfs(int ri, int rj, vector<vector<int>>& grid){
        stack<pair<int, int>> dfsS;
        int area = 1;
        dfsS.emplace(ri, rj);
        visited[ri][rj] = true;

        while(!dfsS.empty()){
            auto [ui, uj] = dfsS.top();

            int nextDir = findNext(ui, uj);
            if(nextDir != -1){ 
                int vi = ui + dir[nextDir][0];
                int vj = uj + dir[nextDir][1];
                if(available(vi, vj, grid)){
                    visited[vi][vj] = true;
                    area++;
                    dfsS.emplace(vi, vj);
                }else{
                    //back edge!
                }
            }else dfsS.pop();
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        next.resize(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end


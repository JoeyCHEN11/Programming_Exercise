/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 *
 * https://leetcode.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (68.73%)
 * Likes:    3895
 * Dislikes: 74
 * Total Accepted:    207.5K
 * Total Submissions: 301.9K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid, where 0 represents a sea cell and
 * 1 represents a land cell.
 * 
 * A move consists of walking from one land cell to another adjacent
 * (4-directionally) land cell or walking off the boundary of the grid.
 * 
 * Return the number of land cells in grid for which we cannot walk off the
 * boundary of the grid in any number of moves.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 3
 * Explanation: There are three 1s that are enclosed by 0s, and one 1 that is
 * not enclosed because its on the boundary.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output: 0
 * Explanation: All 1s are either on the boundary or can reach the
 * boundary.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 500
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

    vector<vector<bool>> visited;
    
    int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    bool available(int i, int j, const vector<vector<int>>& grid){
        return (i >=0 && i < m && j >= 0 && j <n && grid[i][j] == 1 && !visited[i][j]);
    }

    bool isBound(int i, int j) { return i == m - 1 | i == 0 | j == n - 1 | j == 0; }

    int bfs(int ri, int rj, vector<vector<int>>& grid){
        bool isEnclave = !isBound(ri, rj);
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
                    isEnclave = isEnclave & !isBound(vi, vj);
                    area++;
                    visited[vi][vj] = true;

                    bfsQ.emplace(vi, vj);
                }
            }
        }
        return isEnclave? area : 0;
    }


    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    cnt += bfs(i, j, grid);
                }
            }
        }
        return cnt;

    }
};
// @lc code=end


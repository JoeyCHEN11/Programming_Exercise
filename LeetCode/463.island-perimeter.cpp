/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (70.30%)
 * Likes:    6210
 * Dislikes: 333
 * Total Accepted:    494.5K
 * Total Submissions: 703.4K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given row x col grid representing a map where grid[i][j] = 1
 * represents land and grid[i][j] = 0 represents water.
 * 
 * Grid cells are connected horizontally/vertically (not diagonally). The grid
 * is completely surrounded by water, and there is exactly one island (i.e.,
 * one or more connected land cells).
 * 
 * The island doesn't have "lakes", meaning the water inside isn't connected to
 * the water around the island. One cell is a square with side length 1. The
 * grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * Output: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image above.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1]]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,0]]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * row == grid.length
 * col == grid[i].length
 * 1 <= row, col <= 100
 * grid[i][j] is 0 or 1.
 * There is exactly one island in grid.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int m, n;
    int dir[4][2] = {-1, 0, 0, -1, 0, 1, 1, 0};
    vector<vector<bool>> visited;
    bool boundCheck(int i, int j){ return i >= 0 && i < m && j >= 0 && j < n; }

    int bfs(int ri, int rj, vector<vector<int>> & grid){
        int perimeter = 0;
        queue<pair<int, int>> que;
        que.emplace(ri, rj);
        visited[ri][rj] = true;

        while(!que.empty()){
            auto [ui, uj] = que.front(); que.pop();

            for(auto [dx, dy] : dir){
                int vi = ui + dy;
                int vj = uj + dx;
                if(boundCheck(vi, vj) && grid[vi][vj] == 1){
                    if(!visited[vi][vj]){
                        que.emplace(vi, vj);
                        visited[vi][vj] = true;
                    }
                }else perimeter++;
            }
        }
        return perimeter;
    }

    int islandPerimeterCount(vector<vector<int>>& grid){
        //count and compute;
        int cnt = 0;
        int cover = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    cnt++;
                    if(i + 1 < m && grid[i + 1][j]) cover++;
                    if(j + 1 < n && grid[i][j + 1]) cover++;
                }
            }
        }
        return 4 * cnt - 2 * cover;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        //iteration
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //bfs
                //if(grid[i][j]) return bfs(i, j, grid);

                //iter
                // if(grid[i][j]){
                //     for(auto [dx, dy] : dir){
                //         if(!boundCheck(i + dy, j + dx) || !grid[i + dy][j + dx]) ans++;
                //     }
                // }
            }
        }

        return islandPerimeterCount(grid);
    }
};
// @lc code=end


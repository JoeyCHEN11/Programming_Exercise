/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (58.63%)
 * Likes:    22050
 * Dislikes: 486
 * Total Accepted:    2.5M
 * Total Submissions: 4.3M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 * 
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> color;
    int cnt;
    int m, n;
    int directs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
        color[i][j] = cnt;

        if(i - 1 >= 0 && color[i - 1][j] == 0 && grid[i - 1][j] == '1') dfs(i - 1, j, grid);
        if(j - 1 >= 0 && color[i][j - 1] == 0 && grid[i][j - 1] == '1') dfs(i, j - 1, grid);
        if(i + 1 < m && color[i + 1][j] == 0 && grid[i + 1][j] == '1') dfs(i + 1, j, grid);
        if(j + 1 < n && color[i][j + 1] == 0 && grid[i][j + 1] == '1') dfs(i, j + 1, grid);
    }


    void bfs(int ri, int rj, vector<vector<char>>& grid){
        queue<pair<int, int>> bfsQ;
        bfsQ.emplace(ri, rj);
        color[ri][rj] = cnt;
        
        while(!bfsQ.empty()){
            auto [ui, uj] = bfsQ.front(); bfsQ.pop();
            //结束访问（隐式地）

            for(auto dir : directs){
                int vi = ui + dir[0];
                int vj = uj + dir[1];

                if(vi >= 0 && vj >= 0 && vi < m && vj < n && color[vi][vj] == 0 && grid[vi][vj] == '1'){
                    //bfs 开始访问一定在遍历子节点时 
                    color[vi][vj] = cnt;
                    bfsQ.emplace(vi, vj);
                }
            }
        }

    }



    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        cnt = 0;
        color.resize(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && color[i][j] == 0) {
                    cnt++;
                    //dfs
                    dfs(i, j, grid);

                    //bfs
                    //bfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};
// @lc code=end


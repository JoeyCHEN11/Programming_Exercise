/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (53.91%)
 * Likes:    12386
 * Dislikes: 388
 * Total Accepted:    798K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 * 
 * 
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <cstdint>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int m, n;
    vector<vector<int>> timeSlot;
    int dir[4][2] {0, -1, -1, 0, 0, 1, 1, 0};

    bool checkBound(int i, int j){ return i >= 0 && i < m && j >= 0 && j < n; }
    int bfs(vector<vector<int>>& grid){
        queue<pair<int, int>> que;
        
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    que.emplace(i, j);
                    timeSlot[i][j] = 0;
                }else if(grid[i][j] == 1){
                    timeSlot[i][j] = INT32_MAX;
                }
            }
        }

        while(!que.empty()){
            auto [ui, uj] = que.front(); que.pop();

            for(auto [dx, dy] : dir){
                int vi = ui + dx;
                int vj = uj + dy;
                if(checkBound(vi, vj) && grid[vi][vj] == 1){
                    grid[vi][vj] = 2;
                    timeSlot[vi][vj] = timeSlot[ui][uj] + 1;
                    que.emplace(vi, vj);
                }
            }
        }

        int ans = 0;
        for(auto & vec : timeSlot){
            for(auto time : vec){
                ans = max(ans, time);
            }
        }

        return ans == INT32_MAX? -1 : ans;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        timeSlot.resize(m, vector<int>(n, 0));

        return bfs(grid);

    }
};
// @lc code=end


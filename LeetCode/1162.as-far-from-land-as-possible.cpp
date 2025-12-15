/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (51.58%)
 * Likes:    4100
 * Dislikes: 110
 * Total Accepted:    152.4K
 * Total Submissions: 295.5K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * Given an n x n grid containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximized, and return the distance. If no land or water
 * exists in the grid, return -1.
 * 
 * The distance used in this problem is the Manhattan distance: the distance
 * between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation: The cell (1, 1) is as far as possible from all the land with
 * distance 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation: The cell (2, 2) is as far as possible from all the land with
 * distance 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 100
 * grid[i][j] is 0 or 1
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int n;

    vector<vector<int>> distances;
    int dir[4][2] {-1, 0, 0, 1, 1, 0, 0, -1 };
    bool boundCheck(int i, int j){ return i >= 0 && i < n && j >= 0 && j < n; }

    int bfs(vector<vector<int>> grid, queue<pair<int, int>>& que){
        int ans = -1;

        while(!que.empty()){
            auto [ui, uj] = que.front(); que.pop();
            ans = distances[ui][uj];

            for(auto [dx, dy] : dir){
                int vi = ui + dx;
                int vj = uj + dy;
                if(boundCheck(vi, vj) && distances[vi][vj] == INT32_MAX){
                    distances[vi][vj] = distances[ui][uj] + 1;
                    que.emplace(vi, vj);
                }
            }
        }

        return ans;
    }
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        distances.resize(n, vector<int>(n, INT32_MAX));
        queue<pair<int, int>> que;
        for(int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) {
                if(grid[i][j]){
                    distances[i][j] = 0;
                    for(auto [dx, dy] : dir){
                        int ri = i + dx;
                        int rj = j + dy;
                        if(boundCheck(ri, rj) && !grid[ri][rj] && distances[ri][rj] == INT32_MAX){
                            distances[ri][rj] = 1;
                            que.emplace(ri, rj);
                        }
                    }
                }
            }
        }

        return bfs(grid, que);
    }
};
// @lc code=end


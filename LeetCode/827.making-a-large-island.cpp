/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 *
 * https://leetcode.com/problems/making-a-large-island/description/
 *
 * algorithms
 * Hard (46.81%)
 * Likes:    3775
 * Dislikes: 71
 * Total Accepted:    163.7K
 * Total Submissions: 349.8K
 * Testcase Example:  '[[1,0],[0,1]]'
 *
 * You are given an n x n binary matrix grid. You are allowed to change at most
 * one 0 to be 1.
 * 
 * Return the size of the largest island in grid after applying this
 * operation.
 * 
 * An island is a 4-directionally connected group of 1s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,0],[0,1]]
 * Output: 3
 * Explanation: Change one 0 to 1 and connect two 1s, then we get an island
 * with area = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,1],[1,0]]
 * Output: 4
 * Explanation: Change the 0 to 1 and make the island bigger, only one island
 * with area = 4.
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1],[1,1]]
 * Output: 4
 * Explanation: Can't change any 0 to 1, only one island with area = 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 500
 * grid[i][j] is either 0 or 1.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    //思路：染色+计算面积，最后合并，找最大合并面积
    int m, n, c;
    vector<vector<int>> color;
    unordered_map<int, int> areas;
    int dir[4][2] {-1, 0, 0, -1, 1, 0, 0, 1};

    bool available(int i, int j){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int bfs(int ri, int rj, const vector<vector<int>> & grid){
        int area = 1;
        queue<pair<int, int>> que;
        que.emplace(ri, rj);
        color[ri][rj] = c;

        while(!que.empty()){
            auto [ui, uj] = que.front(); que.pop();

            for(auto [dx, dy] : dir){
                int vi = ui + dx;
                int vj = uj + dy;
                if(available(vi, vj) && !color[vi][vj] && grid[vi][vj] == 1){
                    color[vi][vj] = c;
                    area++;
                    que.emplace(vi, vj);
                }
            }
        }
        return area;
    }

    vector<bool> getMergeList(int x, int y){
        vector<bool> mergeList(4, true);
        for(int i = 0; i < 4; i++) {
            auto [dx, dy] = dir[i];
            if(!available(x + dx, y + dy) || !color[x + dx][y + dy]) mergeList[i] = false;
        }

        //优化可读性：改用set
        for(int i = 0; i < 3; i++){
            if(!mergeList[i]) continue;
            auto [idx, idy] = dir[i];
            int ci = color[x + idx][y + idy];
            for(int j = i + 1; j < 4; j++){
                if(!mergeList[j]) continue;
                auto [jdx, jdy] = dir[j];
                int cj = color[x + jdx][y + jdy];
                if(cj == ci) mergeList[j] = false;
            }
        }
        return mergeList;
    }

    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        color.resize(m, vector<int> (n, 0));
        c = 0;
        int maxIsLand = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !color[i][j]){
                    c++;
                    int area = bfs(i, j, grid);
                    maxIsLand = max(maxIsLand, area);
                    areas[c] = area;
                }
            }
        }

        //merge
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) continue;
                int area = 1;
                vector<bool> mergeList = getMergeList(i, j);
                for(int k = 0; k < 4; k++){
                    if(mergeList[k]){
                        auto [dx, dy] = dir[k];
                        area += areas[color[i + dx][j + dy]];
                    }
                }
                maxIsLand = max(area, maxIsLand);
            }
        }

        return maxIsLand;
    }  
};
// @lc code=end


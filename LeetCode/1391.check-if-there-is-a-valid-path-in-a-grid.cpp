/*
 * @lc app=leetcode id=1391 lang=cpp
 *
 * [1391] Check if There is a Valid Path in a Grid
 *
 * https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/
 *
 * algorithms
 * Medium (47.72%)
 * Likes:    803
 * Dislikes: 311
 * Total Accepted:    27.7K
 * Total Submissions: 58K
 * Testcase Example:  '[[2,4,3],[6,5,2]]'
 *
 * You are given an m x n grid. Each cell of grid represents a street. The
 * street of grid[i][j] can be:
 * 
 * 
 * 1 which means a street connecting the left cell and the right cell.
 * 2 which means a street connecting the upper cell and the lower cell.
 * 3 which means a street connecting the left cell and the lower cell.
 * 4 which means a street connecting the right cell and the lower cell.
 * 5 which means a street connecting the left cell and the upper cell.
 * 6 which means a street connecting the right cell and the upper cell.
 * 
 * 
 * You will initially start at the street of the upper-left cell (0, 0). A
 * valid path in the grid is a path that starts from the upper left cell (0, 0)
 * and ends at the bottom-right cell (m - 1, n - 1). The path should only
 * follow the streets.
 * 
 * Notice that you are not allowed to change any street.
 * 
 * Return true if there is a valid path in the grid or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[2,4,3],[6,5,2]]
 * Output: true
 * Explanation: As shown you can start at cell (0, 0) and visit all the cells
 * of the grid to reach (m - 1, n - 1).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,2,1],[1,2,1]]
 * Output: false
 * Explanation: As shown you the street at cell (0, 0) is not connected with
 * any street of any other cell and you will get stuck at cell (0, 0)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,2]]
 * Output: false
 * Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0,
 * 2).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * 1 <= grid[i][j] <= 6
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class DisjointSet
{
private:
    vector<int> rank, forest;

public:
    DisjointSet(int n){
        rank.resize(n,0);
        forest.resize(n,0);
        for(int i = 0; i < n; i++) make_set(i);
    }

    void make_set(int x){
        forest[x] = x;
        rank[x] = 0;
    }

    void unite(int x, int y){
        link_tree(find_set(x),find_set(y));
    }

    void link_tree(int x, int y){
        if(rank[x]<rank[y]) forest[x] = forest[y];
        else {
            if(rank[x]==rank[y]) rank[x]++; 
            forest[y] = forest[x];
        }
    }

    int find_set(int x){
        if(forest[x]!=x) forest[x] = find_set(forest[x]);
        return forest[x];
    }

    bool same(int x, int y) { return find_set(x)==find_set(y);}

    ~DisjointSet(){}
};


using Cell = int [4];

class Solution {
public:
    //dfs检测后向边，或直接用并查集处理
    int m, n;
                // up, right, down, left
    int dir[4][2] {-1, 0, 0, 1, 1, 0, 0, -1};
    //建立六种格子
    Cell cells[6]{
        {false, true, false, true},
        {true, false, true, false},
        {false, false, true, true},
        {false, true, true, false},
        {true, false, false, true},
        {true, true, false, false},
    };
    unordered_map<pair<int, int>, vector<pair<int, int>>> graph;
    bool boundCheck(int i, int j){ return i >= 0 && i < m && j >= 0 && j < n; }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        DisjointSet ds(m * n);
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int u = i * n + j;
                auto uType = cells[grid[i][j] - 1];
                for(int k = 0; k < 4; k++){
                    if(uType[k]){
                        auto [di, dj] = dir[k];
                        int vi = i + di;
                        int vj = j + dj;
                        if(boundCheck(vi, vj) && cells[grid[vi][vj] - 1][(k + 2) % 4]){
                            ds.unite(u, vi * n + vj);
                        }
                    }
                }
            }
        }
        return ds.same(0, m * n - 1);
    }
};
// @lc code=end


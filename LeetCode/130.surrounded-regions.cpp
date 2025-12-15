/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (39.10%)
 * Likes:    8368
 * Dislikes: 1756
 * Total Accepted:    672.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that
 * are 4-directionally surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output:
 * [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Notice that an 'O' should not be flipped if:
 * - It is on the border, or
 * - It is adjacent to an 'O' that should not be flipped.
 * The bottom 'O' is on the border, so it is not flipped.
 * The other three 'O' form a surrounded region, so they are flipped.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["X"]]
 * Output: [["X"]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is 'X' or 'O'.
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
    vector<bool> onEdge;
    DisjointSet(int n){
        rank.resize(n,0);
        forest.resize(n,0);
        onEdge.resize(n, false);
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
        if(rank[x]<rank[y]) {
            forest[x] = forest[y];
            onEdge[y] = onEdge[y] | onEdge[x];    
        }
        else {
            if(rank[x]==rank[y]) rank[x]++; 
            forest[y] = forest[x];
            onEdge[x] = onEdge[y] | onEdge[x];   
        }
    }

    int find_set(int x){
        if(forest[x]!=x) forest[x] = find_set(forest[x]);
        return forest[x];
    }

    bool same(int x, int y) { return find_set(x)==find_set(y);}

    ~DisjointSet(){}
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        DisjointSet ds(n * m);
        ds.onEdge.resize(m * n, false);
        
        for(int i = 0; i < m; i++){ 
            if(board[i][0] == 'O') ds.onEdge[i * n] = true;
            if(board[i][n-1] == 'O') ds.onEdge[i * n + n - 1] = true;
        }
        for(int j = 0; j < n; j++){ 
            if(board[0][j] == 'O') ds.onEdge[j] = true;
            if(board[m - 1][j] == 'O') ds.onEdge[(m - 1) * n + j] = true;
        }

        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n - 1; j++){
                if(board[i][j] == 'O'){
                    if(board[i][j + 1] == 'O') ds.unite(i * n + j, i * n + j + 1);
                    if(board[i + 1][j] == 'O') ds.unite(i * n + j, (i + 1) * n + j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !ds.onEdge[ds.find_set(i * n + j)]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end


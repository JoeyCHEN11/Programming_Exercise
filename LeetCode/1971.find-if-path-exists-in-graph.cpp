/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 *
 * https://leetcode.com/problems/find-if-path-exists-in-graph/description/
 *
 * algorithms
 * Easy (51.56%)
 * Likes:    3412
 * Dislikes: 181
 * Total Accepted:    312K
 * Total Submissions: 605.3K
 * Testcase Example:  '3\n[[0,1],[1,2],[2,0]]\n0\n2'
 *
 * There is a bi-directional graph with n vertices, where each vertex is
 * labeled from 0 to n - 1 (inclusive). The edges in the graph are represented
 * as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a
 * bi-directional edge between vertex ui and vertex vi. Every vertex pair is
 * connected by at most one edge, and no vertex has an edge to itself.
 * 
 * You want to determine if there is a valid path that exists from vertex
 * source to vertex destination.
 * 
 * Given edges and the integers n, source, and destination, return true if
 * there is a valid path from source to destination, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
 * Output: true
 * Explanation: There are two paths from vertex 0 to vertex 2:
 * - 0 → 1 → 2
 * - 0 → 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0,
 * destination = 5
 * Output: false
 * Explanation: There is no path from vertex 0 to vertex 5.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2 * 10^5
 * 0 <= edges.length <= 2 * 10^5
 * edges[i].length == 2
 * 0 <= ui, vi <= n - 1
 * ui != vi
 * 0 <= source, destination <= n - 1
 * There are no duplicate edges.
 * There are no self edges.
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

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        for(auto & e : edges){
            int u = e[0];
            int v = e[1];
            ds.unite(u, v);
        }
        return ds.same(source, destination);
    }
};
// @lc code=end


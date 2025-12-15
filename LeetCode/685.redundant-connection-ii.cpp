/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 *
 * https://leetcode.com/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (34.34%)
 * Likes:    2285
 * Dislikes: 310
 * Total Accepted:    68.6K
 * Total Submissions: 199.7K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * In this problem, a rooted tree is a directed graph such that, there is
 * exactly one node (the root) for which all other nodes are descendants of
 * this node, plus every node has exactly one parent, except for the root node
 * which has no parents.
 * 
 * The given input is a directed graph that started as a rooted tree with n
 * nodes (with distinct values from 1 to n), with one additional directed edge
 * added. The added edge has two different vertices chosen from 1 to n, and was
 * not an edge that already existed.
 * 
 * The resulting graph is given as a 2D-array of edges. Each element of edges
 * is a pair [ui, vi] that represents a directed edge connecting nodes ui and
 * vi, where ui is a parent of child vi.
 * 
 * Return an edge that can be removed so that the resulting graph is a rooted
 * tree of n nodes. If there are multiple answers, return the answer that
 * occurs last in the given 2D-array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: edges = [[1,2],[1,3],[2,3]]
 * Output: [2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 * Output: [4,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ui, vi <= n
 * ui != vi
 * 
 * 
 */
#include <bits/stdc++.h>
#include <vector>
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int NIL = -1;
        int n = edges.size();
        DisjointSet ds(n + 1);
        vector<int> parent(n + 1, NIL);
        
        int conflictEdge = NIL, cycleEdge = NIL;
        for(int i = 0; i < n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            //检测冲突边
            if(parent[v] == NIL){
                parent[v] = u;
                //如果不冲突，检测是否成环
                if(!ds.same(u, v)){
                    //及不冲突也不成环，合并为一棵树
                    ds.unite(u, v);
                }else {
                    cycleEdge = i;
                }
            }else{
                conflictEdge = i;
            }
        }
        if(conflictEdge != -1){
            int v = edges[conflictEdge][1];
            if(cycleEdge != -1) return {parent[v], v};
            else return edges[conflictEdge]; 
        }else return edges[cycleEdge];
    }
};
// @lc code=end


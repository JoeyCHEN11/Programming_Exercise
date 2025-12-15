/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 *
 * https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
 *
 * algorithms
 * Medium (49.63%)
 * Likes:    1968
 * Dislikes: 46
 * Total Accepted:    83.9K
 * Total Submissions: 169.2K
 * Testcase Example:  '3\n[[0,1],[0,2],[1,2]]'
 *
 * You are given an integer n. There is an undirected graph with n nodes,
 * numbered from 0 to n - 1. You are given a 2D integer array edges where
 * edges[i] = [ai, bi] denotes that there exists an undirected edge connecting
 * nodes ai and bi.
 * 
 * Return the number of pairs of different nodes that are unreachable from each
 * other.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, edges = [[0,1],[0,2],[1,2]]
 * Output: 0
 * Explanation: There are no pairs of nodes that are unreachable from each
 * other. Therefore, we return 0.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
 * Output: 14
 * Explanation: There are 14 pairs of nodes that are unreachable from each
 * other:
 * 
 * [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
 * Therefore, we return 14.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * 0 <= edges.length <= 2 * 10^5
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * There are no repeated edges.
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int cnt = 0;
    long long ans = 0;
    vector<bool> visited;
    vector<vector<int>> graph;
    
    int bfs(int r, vector<vector<int>> & g){
        int compSize = 1;
        queue<int> que;
        que.emplace(r);
        visited[r] = true;
        
        while(!que.empty()){
            int u = que.front(); que.pop();

            for(auto & v : g[u]){
                if(!visited[v]){
                    visited[v] = true;
                    compSize++;
                    que.emplace(v);
                }
            }
        }
        return compSize;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        visited.resize(n, false);
        graph.resize(n);

        for(const auto & e : edges){
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                long long cmp = bfs(i, graph);
                ans = ans + cnt * cmp;
                cnt += cmp;
                
            }
        }
        return ans;
    }
};
// @lc code=end


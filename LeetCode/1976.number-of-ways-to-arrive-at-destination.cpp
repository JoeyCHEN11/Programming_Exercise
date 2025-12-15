/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 *
 * https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
 *
 * algorithms
 * Medium (28.19%)
 * Likes:    2631
 * Dislikes: 114
 * Total Accepted:    54.1K
 * Total Submissions: 192.4K
 * Testcase Example:  '7\n' +
  '[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]'
 *
 * You are in a city that consists of n intersections numbered from 0 to n - 1
 * with bi-directional roads between some intersections. The inputs are
 * generated such that you can reach any intersection from any other
 * intersection and that there is at most one road between any two
 * intersections.
 * 
 * You are given an integer n and a 2D integer array roads where roads[i] =
 * [ui, vi, timei] means that there is a road between intersections ui and vi
 * that takes timei minutes to travel. You want to know in how many ways you
 * can travel from intersection 0 to intersection n - 1 in the shortest amount
 * of time.
 * 
 * Return the number of ways you can arrive at your destination in the shortest
 * amount of time. Since the answer may be large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 7, roads =
 * [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
 * Output: 4
 * Explanation: The shortest amount of time it takes to go from intersection 0
 * to intersection 6 is 7 minutes.
 * The four ways to get there in 7 minutes are:
 * - 0 ➝ 6
 * - 0 ➝ 4 ➝ 6
 * - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
 * - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2, roads = [[1,0,10]]
 * Output: 1
 * Explanation: There is only one way to go from intersection 0 to intersection
 * 1, and it takes 10 minutes.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 200
 * n - 1 <= roads.length <= n * (n - 1) / 2
 * roads[i].length == 3
 * 0 <= ui, vi <= n - 1
 * 1 <= timei <= 10^9
 * ui != vi
 * There is at most one road connecting any two intersections.
 * You can reach any intersection from any other intersection.
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    using ll = long long;
    ll MOD = 1e9 + 7;
    int INF = INT32_MAX;
    vector<vector<pair<int, int>>> graph;
    vector<ll> distToSource;
    //dp;
    vector<ll> ways;
    int dijkstraCnt(int r, int n){
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.emplace(0, r);
        //distToSource[r] = 0;
        ways[r] = 1;

        while(!pq.empty()){
            auto [w, u] = pq.top(); pq.pop();
            
            if(w > distToSource[u]) continue;
            
            for(auto & edge : graph[u]){
                auto [c, v] = edge;
                if(c + w < distToSource[v]){
                    distToSource[v] = w + c;
                    pq.emplace(c + w, v);
                    ways[v] = ways[u];
                }else if(c + w == distToSource[v]) ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
        return ways[n - 1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        graph.resize(n);
        distToSource.resize(n, LONG_LONG_MAX);
        ways.resize(n, 0);
        for(auto & edge :  roads){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].emplace_back(w, v);
            graph[v].emplace_back(w, u);
        }
        return dijkstraCnt(0, n);
    }
};
// @lc code=end


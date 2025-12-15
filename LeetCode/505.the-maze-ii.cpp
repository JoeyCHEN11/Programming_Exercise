/**

 There is a ball in a maze with empty spaces (represented as 0) 
 and walls (represented as 1). The ball can go through the empty spaces by
 rolling up, down, left or right, but it won't stop rolling until hitting a 
 wall. When the ball stops, it could choose the next direction.

 Given the m x n maze, the ball's start position and the destination, 
 where start = [startrow, startcol] and destination = [destinationrow, 
 destinationcol], return the shortest distance for the ball to stop at the 
 destination. If the ball cannot stop at destination, return -1.

 The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

  You may assume that the borders of the maze are all walls (see examples).
 * @file 505.the-maze-ii.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // struct Cell{
    //     bool walls[4] {false, false, false, false};
    // };
    int dir[4][2] {-1, 0, 0, 1, 1, 0, 0, -1};
    vector<vector<pair<int, int>>> graph;
    vector<int> distance;
    int m, n;
    bool boundCheck(int i, int j){ return i >= 0 && i < m && j >= 0 && j < n; }
    void bfs(int ri, int rj){
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, ri * n + rj);
        while(!pq.empty()){
            auto [w, u] = pq.top(); pq.pop();

            if(w > distance[u]) continue;

            for(auto [v, c] : graph[u]){
                if(c + w < distance[v]){
                    distance[v] = c + w;
                    pq.emplace(c + w, v);
                } 
            }
        }
    }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = maze[0].size();
        graph.resize(m * n);
        distance.resize(m * n, INT32_MAX);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(maze[i][j]) continue;
                for(auto [dx, dy] : dir){
                    int vi = i, vj = j;
                    while(boundCheck(vi, vj) && !maze[vi][vj]){
                        vi += dx;
                        vj += dy;
                    }
                    vi -= dx; vj -= dy;
                    if(vi != i || vj != j){
                        graph[i * n + j].emplace_back(vi * n + vj, abs(vi - i) + abs(vj - j));
                    }
                }
            }
        }
        bfs(start[0], start[1]);
        for(int i = 0; i < m * n; i++) {
            cout<<i/n<<", "<<i%n<<": "<<endl;
            for(auto [v, w] : graph[i]){
                cout<<v/n<<", "<<v%n<<", "<<"weight: "<<w<<endl;;
            }
        }
        return (distance[destination[0] * n + destination[1]] == INT32_MAX? -1 : distance[destination[0] * n + destination[1]]);
    }
};
/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 *
 * https://leetcode.com/problems/keys-and-rooms/description/
 *
 * algorithms
 * Medium (72.75%)
 * Likes:    5960
 * Dislikes: 271
 * Total Accepted:    414.4K
 * Total Submissions: 569.5K
 * Testcase Example:  '[[1],[2],[3],[]]'
 *
 * There are n rooms labeled from 0 to n - 1 and all the rooms are locked
 * except for room 0. Your goal is to visit all the rooms. However, you cannot
 * enter a locked room without having its key.
 * 
 * When you visit a room, you may find a set of distinct keys in it. Each key
 * has a number on it, denoting which room it unlocks, and you can take all of
 * them with you to unlock the other rooms.
 * 
 * Given an array rooms where rooms[i] is the set of keys that you can obtain
 * if you visited room i, return true if you can visit all the rooms, or false
 * otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: rooms = [[1],[2],[3],[]]
 * Output: true
 * Explanation: 
 * We visit room 0 and pick up key 1.
 * We then visit room 1 and pick up key 2.
 * We then visit room 2 and pick up key 3.
 * We then visit room 3.
 * Since we were able to visit every room, we return true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: rooms = [[1,3],[3,0,1],[2],[0]]
 * Output: false
 * Explanation: We can not enter room number 2 since the only key that unlocks
 * it is in that room.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == rooms.length
 * 2 <= n <= 1000
 * 0 <= rooms[i].length <= 1000
 * 1 <= sum(rooms[i].length) <= 3000
 * 0 <= rooms[i][j] < n
 * All the values of rooms[i] are unique.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> visited;
    int dfsCnt = 0;
    
    int bfs(int r, const vector<vector<int>> & rooms){
        int cnt = 1;
        queue<int> que;
        que.emplace(r);
        visited[r] = true;
        while(!que.empty()){
            int u = que.front(); que.pop();

            for(int i = 0; i < rooms[u].size(); i++){
                int v = rooms[u][i];
                if(!visited[v]){
                    cnt++;
                    visited[v] = true;
                    que.emplace(v);
                }
            }
        }
        return cnt;
    }

    void dfs(int u, const vector<vector<int>> & rooms){
        dfsCnt++;
        visited[u] = true;
        for(auto v : rooms[u]){
            if(visited[v] == false) dfs(v, rooms);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.resize(rooms.size(), false);

        // dfs(0, rooms);
        // return dfsCnt == rooms.size();

        return bfs(0, rooms) == rooms.size();
    }
};
// @lc code=end


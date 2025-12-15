/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (46.60%)
 * Likes:    15834
 * Dislikes: 670
 * Total Accepted:    1.5M
 * Total Submissions: 3.2M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 * 
 * 
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 * 
 * 
 * Return true if you can finish all courses. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 * 
 * 
 */
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> inDeg;
    vector<bool> sorted;
    //vector<int> sortedCourses;

    int topoBFS(int r){
        queue<int> que;
        int cnt = 1;
        sorted[r] = true;
        que.emplace(r);

        while(!que.empty()){
            int u = que.front(); que.pop();

            for(int v : graph[u]){
                if(!sorted[v]){
                    inDeg[v]--;
                    if(inDeg[v] == 0){
                        que.emplace(v);
                        sorted[v] = true;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int ans = 0;
        inDeg.resize(numCourses, 0);
        graph.resize(numCourses);
        sorted.resize(numCourses, false);
    
        for(auto pre : prerequisites){
            int v = pre[0];
            int u = pre[1];
            inDeg[v]++;
            graph[u].emplace_back(v);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(!sorted[i] && !inDeg[i]) ans += topoBFS(i);
        }
        return ans == numCourses;
    }
};
// @lc code=end


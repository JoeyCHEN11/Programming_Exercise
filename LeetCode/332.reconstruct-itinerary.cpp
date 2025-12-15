/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Hard (43.29%)
 * Likes:    5753
 * Dislikes: 1850
 * Total Accepted:    414.5K
 * Total Submissions: 958.3K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * You are given a list of airline tickets where tickets[i] = [fromi, toi]
 * represent the departure and the arrival airports of one flight. Reconstruct
 * the itinerary in order and return it.
 * 
 * All of the tickets belong to a man who departs from "JFK", thus, the
 * itinerary must begin with "JFK". If there are multiple valid itineraries,
 * you should return the itinerary that has the smallest lexical order when
 * read as a single string.
 * 
 * 
 * For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * 
 * 
 * You may assume all tickets form at least one valid itinerary. You must use
 * all the tickets once and only once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
 * Output: ["JFK","MUC","LHR","SFO","SJC"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: tickets =
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= tickets.length <= 300
 * tickets[i].length == 2
 * fromi.length == 3
 * toi.length == 3
 * fromi and toi consist of uppercase English letters.
 * fromi != toi
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


class Solution {
private:

    int N;
    const string ROOT = "JFK";
    bool solved;
    //unordered_map<string, vector<Ticket>> graph;
    
    //weighted graph
    unordered_map<string, map<string, int>> graph;

    //graph for hierholzer
    unordered_map<string, priority_queue<string, vector<string>, greater<string> > > hgraph;
    vector<string> ans;

    void backTrack(const string & r){
        if(ans.size() == N){
            solved = true;
            return;
        }

        for(auto & [dest, remain] : graph[r]){
            if(remain == 0) continue;

            remain--;
            ans.emplace_back(dest);
            backTrack(dest);
            if(!solved){
                ans.pop_back();
                remain++;
            }else return;
        }
    }

    void hierholzer(const string & r){

        while(hgraph[r].size() > 0){
            string dest = hgraph[r].top(); hgraph[r].pop();
            
            hierholzer(dest);
        }
        ans.push_back(r);

    }



public:

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //sort(tickets.begin(), tickets.end());
        N = tickets.size() + 1;
        solved = false;
        for(auto & t : tickets){
            //graph[t[0]][t[1]]++;
            hgraph[t[0]].push(t[1]);
        }

        //back tracking
        // ans.push_back(ROOT);
        // backTrack(ROOT);

        //hierholzer's algorithm
        hierholzer(ROOT);
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
// @lc code=end


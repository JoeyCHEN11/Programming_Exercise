/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Hard (38.89%)
 * Likes:    11770
 * Dislikes: 1864
 * Total Accepted:    1M
 * Total Submissions: 2.7M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * A transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... ->
 * sk such that:
 * 
 * 
 * Every adjacent pair of words differs by a single letter.
 * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need
 * to be in wordList.
 * sk == endWord
 * 
 * 
 * Given two words, beginWord and endWord, and a dictionary wordList, return
 * the number of words in the shortest transformation sequence from beginWord
 * to endWord, or 0 if no such sequence exists.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot"
 * -> "dog" -> cog", which is 5 words long.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: 0
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the words in wordList are unique.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution{
public:
    //转用set提高搜索效率
    unordered_set<string> wordSet;
    unordered_map<string, int> dis;


    bool availabe(const string & s){
        return wordSet.find(s) != wordSet.end() && dis.find(s) == dis.end();
    }

    void bfs(string root){
        dis[root] = 0;
        queue<string> que;
        que.emplace(root);

        while(!que.empty()){
            string u = que.front(); que.pop();
            //枚举所有位置
            for(int i = 0; i < u.size(); i++){
                string v = u;
                //枚举所有更改的字符
                for(int j = 0; j < 26; j++){

                    v[i] = j + 'a';
                    if(availabe(v)){
                        dis[v] = dis[u] + 1;
                        que.emplace(v);
                    }
                }
            }
        }  
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordSet.insert(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) return 0;

        bfs(beginWord);
        return dis.find(endWord) == dis.end()? 0 : dis[endWord] + 1;

    }
};

//brute force
// class bruteForce {
// public:
//     int n;
//     int end;
//     vector<vector<int>> graph;
//     vector<int> distances;

//     bool connected(const string & s1, const string & s2){
//         int cnt = 0;
//         for(int i = 0; i < s1.size() && cnt <= 1; i++){
//             if(s1[i] != s2[i]) cnt++;
//         }
//         return cnt == 1;
//     }

//     void bfs(int r){
//         distances[r] = 0;
//         queue<int> que;
//         que.push(r);

//         while(!que.empty()){
            
//             int u = que.front(); que.pop();

//             for(int v : graph[u]){
//                 if(distances[v] == -1){
//                     distances[v] = distances[u] + 1;
//                     que.push(v);
//                 }
//             }
//         }
//     }

//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         end = -1;
//         n = wordList.size();
//         graph.resize(n + 1);
//         distances.resize(n + 1, -1);

//         //build the graph
//         for(int i = 0; i < n; i++){
//             if(wordList[i] == endWord) end = i;
//             if(connected(beginWord, wordList[i])){
//                 graph[i].push_back(n);
//                 graph[n].push_back(i);
//             }
//             for(int j = i + 1; j < n; j++){
//                 if(connected(wordList[i], wordList[j])){
//                     graph[i].push_back(j);
//                     graph[j].push_back(i);
//                 }
//             }
//         }
//         if(end == -1 || graph[n].empty()) return 0;

//         bfs(n);
//         return distances[end] + 1;

//     }
// };
// @lc code=end


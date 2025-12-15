/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * algorithms
 * Medium (56.78%)
 * Likes:    9293
 * Dislikes: 3735
 * Total Accepted:    1.2M
 * Total Submissions: 2.1M
 * Testcase Example:  '[[2,4],[1,3],[2,4],[1,3]]'
 *
 * Given a reference of a node in a connected undirected graph.
 * 
 * Return a deep copy (clone) of the graph.
 * 
 * Each node in the graph contains a value (int) and a list (List[Node]) of its
 * neighbors.
 * 
 * 
 * class Node {
 * ⁠   public int val;
 * ⁠   public List<Node> neighbors;
 * }
 * 
 * 
 * 
 * 
 * Test case format:
 * 
 * For simplicity, each node's value is the same as the node's index
 * (1-indexed). For example, the first node with val == 1, the second node with
 * val == 2, and so on. The graph is represented in the test case using an
 * adjacency list.
 * 
 * An adjacency list is a collection of unordered lists used to represent a
 * finite graph. Each list describes the set of neighbors of a node in the
 * graph.
 * 
 * The given node will always be the first node with val = 1. You must return
 * the copy of the given node as a reference to the cloned graph.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
 * Output: [[2,4],[1,3],[2,4],[1,3]]
 * Explanation: There are 4 nodes in the graph.
 * 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val =
 * 4).
 * 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val =
 * 3).
 * 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val =
 * 4).
 * 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val =
 * 3).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: adjList = [[]]
 * Output: [[]]
 * Explanation: Note that the input contains one empty list. The graph consists
 * of only one node with val = 1 and it does not have any neighbors.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: adjList = []
 * Output: []
 * Explanation: This an empty graph, it does not have any nodes.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the graph is in the range [0, 100].
 * 1 <= Node.val <= 100
 * Node.val is unique for each node.
 * There are no repeated edges and no self-loops in the graph.
 * The Graph is connected and all nodes can be visited starting from the given
 * node.
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> dfsCheck;
    Node* cloneDfs(Node* node){
        if(!node) return nullptr;
        if(dfsCheck.find(node->val) != dfsCheck.end()) return dfsCheck[node->val];

        Node* u = new Node(node->val);
        dfsCheck[node->val] = u;

        for(auto v : node->neighbors){
            u->neighbors.emplace_back(cloneDfs(v));
        }
        return u;
    }

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<int, Node*> check;
        queue<Node*> que;
        Node* root = new Node(node->val);

        
        check[node->val] = root;
        que.emplace(node);
        
        while(!que.empty()){
            Node* u = que.front(); que.pop();
            Node* cloneU = check[u->val];

            for(auto v : u->neighbors){
                if(!check[v->val]){
                    check[v->val] = new Node(v->val);
                    que.emplace(v);
                }
                cloneU->neighbors.push_back(check[v->val]);
            }
        }
        
        return root;

        //return cloneDfs(node);

    }
};
// @lc code=end


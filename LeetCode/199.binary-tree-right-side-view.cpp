#ifndef struct TreeNode
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
#endif
/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (62.72%)
 * Likes:    11596
 * Dislikes: 853
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to
 * bottom.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,3]
 * Output: [1,3]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if(!root) return {};
        vector<int> ans;

        //bfs
        queue<TreeNode *> q;
        q.emplace(root);

        while(!q.empty()){
            int level_n = q.size();
            TreeNode* u;
            while(level_n--){
                u = q.front(); q.pop();
                if(u->left) q.emplace(u->left);
                if(u->right) q.emplace(u->right);
            }
            ans.push_back(u->val);
        }

        //dfs
        // stack<pair<TreeNode*, int>> dfs_s;
        // map<int, int> rmv;

        // dfs_s.emplace(root, 0);

        // while(!dfs_s.empty()){
        //     auto [u, d] = dfs_s.top(); dfs_s.pop();

        //     if(rmv.find(d) == rmv.end()) rmv[d] = u->val;

        //     if(u->left) dfs_s.emplace(u->left, d + 1);
        //     if(u->right) dfs_s.emplace(u->right, d + 1); 
        // }
        
        // for(auto [d, v] : rmv) ans.push_back(v);
        return ans;
    }
};
// @lc code=end


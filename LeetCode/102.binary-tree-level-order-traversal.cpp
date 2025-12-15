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
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (66.57%)
 * Likes:    14897
 * Dislikes: 298
 * Total Accepted:    2.1M
 * Total Submissions: 3.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: [[1]]
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
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
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

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        
        queue<pair<TreeNode *,int>> lo_q;
        lo_q.emplace(root, 0);
        while(!lo_q.empty()){
            auto [u, level] = lo_q.front(); lo_q.pop();
            if(level < ans.size()) ans[level].emplace_back(u->val);
            else ans.emplace_back(1, u->val);
            if(u->left) lo_q.emplace(u->left, level + 1);
            if(u->right) lo_q.emplace(u->right, level + 1);
        }


        // queue<TreeNode *> q;
        // q.emplace(root);
        // vector<int> level;
        // while(!q.empty()){

        //     int level_n = q.size();
        //     level.clear();
        //     while(level_n--){
        //         TreeNode* u = q.front(); q.pop();

        //         level.emplace_back(u->val);
        //         if(u->left) q.emplace(u->left);
        //         if(u->right) q.emplace(u->right);
        //     }
        //     ans.push_back(level);
        // }

        return ans;
    }
};
// @lc code=end


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
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (68.93%)
 * Likes:    7784
 * Dislikes: 202
 * Total Accepted:    1.5M
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
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
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
#include <stack>

using namespace std;

class Solution {
public:
    void preorder_rec(vector<int>& ans, TreeNode* u){
        if(!u) return;
        ans.push_back(u->val);
        if(u->left) preorder_rec(ans, u->left);
        if(u->right) preorder_rec(ans, u->right);
    }

    void preorder_iter(vector<int>& ans, TreeNode* r){
        ans.clear();
        if(!r) return;
        stack<TreeNode*> s;

        s.push(r);
        while(!s.empty()){
            TreeNode* u = s.top(); s.pop();
            if(u){
                if(u->right) s.push(u->right);
                if(u->left) s.push(u->left);
                s.push(u);
                s.push(nullptr);
            }else{
                u = s.top(); s.pop();
                ans.push_back(u->val);
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder_iter(ans, root);
        return ans;
    }
};
// @lc code=end


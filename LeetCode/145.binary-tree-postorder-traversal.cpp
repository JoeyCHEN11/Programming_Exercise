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
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (70.32%)
 * Likes:    6709
 * Dislikes: 183
 * Total Accepted:    1.1M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the postorder traversal of its
 * nodes' values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
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
 * The number of the nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    void postoder_iter(vector<int>& ans, TreeNode* r){
        ans.clear();
        if(!r) return;
        stack<TreeNode*> s;

        s.push(r);
        while(!s.empty()){
            TreeNode* u = s.top(); s.pop();
            if(u){
                s.push(u);
                s.push(nullptr);
                if(u->right) s.push(u->right);
                if(u->left) s.push(u->left);
            }else{
                u = s.top(); s.pop();
                ans.push_back(u->val);
            }
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postoder_iter(ans, root);
        return ans;
    }
};
// @lc code=end


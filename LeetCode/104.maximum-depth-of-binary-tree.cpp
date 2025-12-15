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
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (74.99%)
 * Likes:    12419
 * Dislikes: 212
 * Total Accepted:    2.9M
 * Total Submissions: 3.8M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return its maximum depth.
 * 
 * A binary tree's maximum depth is the number of nodes along the longest path
 * from the root node down to the farthest leaf node.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,2]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
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

using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> bfs_q;
        int depth = 0;
        if(root) bfs_q.emplace(root);


        while(!bfs_q.empty()){
            
            int length = bfs_q.size();
            while(length--){
                TreeNode* u = bfs_q.front(); bfs_q.pop();
                if(u->left) bfs_q.emplace(u->left);
                if(u->right) bfs_q.emplace(u->right);
            }
            depth++;
        }
        return depth;

        // dfs
        // if(!root) return 0;
        // int left_dep = 0;
        // int right_dep = 0;
        // left_dep = maxDepth(root->left) + 1;
        // right_dep = maxDepth(root->right) + 1;
        // return max(left_dep, right_dep);
    }
};
// @lc code=end


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
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.33%)
 * Likes:    7126
 * Dislikes: 1285
 * Total Accepted:    1.1M
 * Total Submissions: 2.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^5].
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
    int minDepth(TreeNode* root) {
        //bfs
        queue<TreeNode *> bfs_q;
        int min_depth = 0;
        if(root) bfs_q.emplace(root);


        while(!bfs_q.empty()){
            
            int length = bfs_q.size();
            min_depth++;
            while(length--){
                TreeNode* u = bfs_q.front(); bfs_q.pop();
                if(!u->left && !u->right) return min_depth;
                else{
                    if(u->left) bfs_q.emplace(u->left);
                    if(u->right) bfs_q.emplace(u->right);
                }
            }
        }

        //dfs
        // if(!root) return 0;

        // if(!root->left && !root->right) return 1;

        // int min_depth = __INT32_MAX__;
        // if(root->left) min_depth = min(minDepth(root->left) + 1, min_depth) ;
        // if(root->right) min_depth = min(minDepth(root->right) + 1, min_depth);
        

        return min_depth;
    }
};
// @lc code=end


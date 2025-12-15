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
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (65.64%)
 * Likes:    3546
 * Dislikes: 112
 * Total Accepted:    327.8K
 * Total Submissions: 499.4K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given the root of a binary tree, return an array of the largest value in
 * each row of the tree (0-indexed).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,3,2,5,3,null,9]
 * Output: [1,3,9]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3]
 * Output: [1,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree will be in the range [0, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> ans;
        queue<TreeNode *> bfs_q;
        if(root) bfs_q.emplace(root);
        while(!bfs_q.empty()){

            int length = bfs_q.size();
            int max_v = -__INT32_MAX__ - 1;
            while(length--){
                TreeNode* u = bfs_q.front(); bfs_q.pop();
                max_v = max(max_v, u->val);

                if(u->left) bfs_q.emplace(u->left);
                if(u->right) bfs_q.emplace(u->right);
            }
            ans.push_back(max_v);
        }
        return ans;
    }
};
// @lc code=end


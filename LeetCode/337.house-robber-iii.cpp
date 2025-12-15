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
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (54.15%)
 * Likes:    8383
 * Dislikes: 139
 * Total Accepted:    372.3K
 * Total Submissions: 687.2K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called root.
 * 
 * Besides the root, each house has one and only one parent house. After a
 * tour, the smart thief realized that all houses in this place form a binary
 * tree. It will automatically contact the police if two directly-linked houses
 * were broken into on the same night.
 * 
 * Given the root of the binary tree, return the maximum amount of money the
 * thief can rob without alerting the police.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,2,3,null,3,null,1]
 * Output: 7
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,4,5,1,3,null,1]
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * 0 <= Node.val <= 10^4
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
#include <bits/stdc++.h>
using namespace std;

//current : 不管偷还是不偷，到该节点为止所偷取的最大值
//last : 不偷该节点，即到该节点的左右子树为止所偷取的最大值之和
struct Status{
    int current;
    int last;
};

struct SubTreeStatus{
    int select;
    int notSelect;
};

class Solution {
public:
    //Offical solution
    SubTreeStatus robTreeOffical(TreeNode* r){
        if(!r) return {0, 0};

        SubTreeStatus left = robTreeOffical(r->left);
        SubTreeStatus right = robTreeOffical(r->right);

        int select = left.notSelect + right.notSelect + r->val;
        int notSelect = max(left.select, left.notSelect) + max(right.select, right.notSelect);
        return {select, notSelect};
    }
    
    Status robTree(TreeNode* r){
        if(!r) return {0, 0};

        Status left = robTree(r->left);
        Status right = robTree(r->right);
        
        //两种选择：偷或不偷
        int curr = max(left.current + right.current, left.last + right.last + r->val);
        
        //            到子树为止的最大值，左右current相加即可
        return {curr, left.current + right.current};
    }



    int rob(TreeNode* root) {
        // SubTreeStatus ans = robTreeOffical(root);
        // return max(ans.select, ans.notSelect);
    
        return robTree(root).current;
    }
};
// @lc code=end


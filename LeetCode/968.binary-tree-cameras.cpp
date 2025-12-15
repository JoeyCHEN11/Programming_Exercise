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
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
 *
 * https://leetcode.com/problems/binary-tree-cameras/description/
 *
 * algorithms
 * Hard (46.51%)
 * Likes:    5206
 * Dislikes: 72
 * Total Accepted:    133.7K
 * Total Submissions: 287.4K
 * Testcase Example:  '[0,0,null,0,0]'
 *
 * You are given the root of a binary tree. We install cameras on the tree
 * nodes where each camera at a node can monitor its parent, itself, and its
 * immediate children.
 * 
 * Return the minimum number of cameras needed to monitor all nodes of the
 * tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [0,0,null,0,0]
 * Output: 1
 * Explanation: One camera is enough to monitor all nodes if placed as shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [0,0,null,0,null,0,null,null,0]
 * Output: 2
 * Explanation: At least two cameras are needed to monitor all nodes of the
 * tree. The above image shows one of the valid configurations of camera
 * placement.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val == 0
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
//[0,null,0,0,0,0,0,0,0,0,0,0,0,0,null,null,null,0,0,0,0,0,null,0,0,null]
struct Status{
    int a, b, c;
    //状态 a：root 必须放置摄像头的情况下，覆盖整棵树需要的摄像头数目
    //状态 b：覆盖整棵树需要的摄像头数目，无论root是否放置摄像头
    //状态 c：覆盖两棵子树需要的摄像头数目，无论节点root本身是否被监控到。
};

class Solution {
public:
    static const int SET = 0;
    static const int MONITORED = 1;
    static const int NOT_MONITORED = 2;
    int cnt;

    int setCamGreedy(TreeNode * u){
        if(!u) return MONITORED;

        int leftFlag = setCamGreedy(u->left);
        int rightFlag = setCamGreedy(u->right);

        if(leftFlag == NOT_MONITORED || rightFlag == NOT_MONITORED ){
            cnt++;
            return SET;
        }else if(leftFlag == SET || rightFlag == SET){
            return MONITORED;
        }else return NOT_MONITORED;

    }

    Status setCamDP(TreeNode * u){
        if(!u) return {INT_MAX/2, 0, 0};

        auto [la, lb, lc] = setCamDP(u->left);
        auto [ra, rb, rc] = setCamDP(u->right);

        int a = lc + rc + 1;
        int b = min(a, min(la + rb, lb + ra));
        int c = min(a, lb + rb);
        return {a, b, c};
    }

    int minCameraCover(TreeNode* root) {

        int rootState = setCamGreedy(root);
        if(rootState == NOT_MONITORED) cnt++;

        //tree dp
        //auto [a, b, c] = setCamDP(root);

        return cnt;

    }
};
// @lc code=end


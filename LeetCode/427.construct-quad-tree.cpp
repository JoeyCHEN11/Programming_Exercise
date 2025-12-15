/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 *
 * https://leetcode.com/problems/construct-quad-tree/description/
 *
 * algorithms
 * Medium (75.28%)
 * Likes:    1474
 * Dislikes: 1811
 * Total Accepted:    118.4K
 * Total Submissions: 157.2K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * Given a n * n matrix grid of 0's and 1's only. We want to represent grid
 * with a Quad-Tree.
 * 
 * Return the root of the Quad-Tree representing grid.
 * 
 * A Quad-Tree is a tree data structure in which each internal node has exactly
 * four children. Besides, each node has two attributes:
 * 
 * 
 * val: True if the node represents a grid of 1's or False if the node
 * represents a grid of 0's. Notice that you can assign the val to True or
 * False when isLeaf is False, and both are accepted in the answer.
 * isLeaf: True if the node is a leaf node on the tree or False if the node has
 * four children.
 * 
 * 
 * 
 * class Node {
 * ⁠   public boolean val;
 * ⁠   public boolean isLeaf;
 * ⁠   public Node topLeft;
 * ⁠   public Node topRight;
 * ⁠   public Node bottomLeft;
 * ⁠   public Node bottomRight;
 * }
 * 
 * We can construct a Quad-Tree from a two-dimensional area using the following
 * steps:
 * 
 * 
 * If the current grid has the same value (i.e all 1's or all 0's) set isLeaf
 * True and set val to the value of the grid and set the four children to Null
 * and stop.
 * If the current grid has different values, set isLeaf to False and set val to
 * any value and divide the current grid into four sub-grids as shown in the
 * photo.
 * Recurse for each of the children with the proper sub-grid.
 * 
 * 
 * If you want to know more about the Quad-Tree, you can refer to the wiki.
 * 
 * Quad-Tree format:
 * 
 * You don't need to read this section for solving the problem. This is only if
 * you want to understand the output format here. The output represents the
 * serialized format of a Quad-Tree using level order traversal, where null
 * signifies a path terminator where no node exists below.
 * 
 * It is very similar to the serialization of the binary tree. The only
 * difference is that the node is represented as a list [isLeaf, val].
 * 
 * If the value of isLeaf or val is True we represent it as 1 in the list
 * [isLeaf, val] and if the value of isLeaf or val is False we represent it as
 * 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,1],[1,0]]
 * Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
 * Explanation: The explanation of this example is shown below:
 * Notice that 0 represents False and 1 represents True in the photo
 * representing the Quad-Tree.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: grid =
 * [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
 * Output:
 * [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
 * Explanation: All values in the grid are not the same. We divide the grid
 * into four sub-grids.
 * The topLeft, bottomLeft and bottomRight each has the same value.
 * The topRight have different values so we divide it into 4 sub-grids where
 * each has the same value.
 * Explanation is shown in the photo below:
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length == grid[i].length
 * n == 2^x where 0 <= x <= 6
 * 
 * 
 */
 #include <bits/stdc++.h>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    vector<vector<int>> pre;

    //range [[0, i), [0, j)] prefix sum.
    void buildPre(vector<vector<int>> & grid){
        int n = grid.size();
        pre.resize(n + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
    }
    // range: [[up, down), [left, down)];
    int getSum(int up, int down, int left, int right){
        return pre[down][right] - pre[down][left] - pre[up][right] + pre[up][left];
    }
    
    Node* constructPre(vector<vector<int>>& grid, int up, int down, int left, int right){
        if(right - left <= 1) return new Node(grid[up][left], true);

        int rangeSum = getSum(up, down, left, right);
        if(rangeSum != 0 && rangeSum != (down - up) * (right - left)){
            return new Node(
                            0, 
                            false,
                            constructPre(grid, up, (up + down) / 2, left, (left + right) / 2), 
                            constructPre(grid, up, (up + down) / 2, (left + right) / 2, right), 
                            constructPre(grid, (up + down) / 2, down, left, (left + right) / 2),
                            constructPre(grid, (up + down) / 2, down, (left + right) / 2, right)
            );
        }else return new Node(grid[up][left], true);
    }

    Node* constructRange(vector<vector<int>>& grid, int up, int down, int left, int right){
        if(right - left <= 1) return new Node(grid[up][left], true);

        bool val = grid[up][left];
        for(int i = up; i < down; i++){
            for(int j = left; j < right; j++){
                if(!val == grid[i][j]){
                    Node * topleft = constructRange(grid, up, (up + down) / 2, left, (left + right) / 2);
                    Node * topright = constructRange(grid, up, (up + down) / 2, (left + right)  / 2, right);
                    Node * bottomleft = constructRange(grid, (up + down) / 2, down, left, (left + right) / 2);
                    Node * bottomright = constructRange(grid, (up + down) / 2, down, (left + right)  / 2, right);

                    return new Node(0, false, topleft, topright, bottomleft, bottomright);
                }
            }
        }

        return new Node(val, true);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        buildPre(grid);
        return constructPre(grid, 0, n, 0, n);
    }
};
// @lc code=end


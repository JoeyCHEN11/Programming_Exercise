/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int up = 0;
        int left = 0;
        int down = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        //draw the whole line and delete it for every for loop
        //any two bounds going through each other indicates that there is no more row/coloumn to be pushed, then break  
        while(true){
            int i;    
            // draw whole first line
            for(i = left; i <= right; i++) ans.push_back(matrix[up][i]);
            //delete first line, move up bound
            if(++up > down) break;
            
            
            for(i = up; i <= down; i++) ans.push_back(matrix[i][right]);
            if(--right < left) break;

            for(i = right; i >= left ; i--) ans.push_back(matrix[down][i]);
            if(--down < up) break;

            for(i = down; i >= up ; i--) ans.push_back(matrix[i][left]);
            if(++left > right) break;
        }

        return ans;
    }
};
// @lc code=end


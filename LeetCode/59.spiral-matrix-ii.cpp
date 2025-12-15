/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        
        int cnt = 1;
        int offset = 1;
        
        if(n%2 == 1) ans[n/2][n/2] = n*n;
        for(int len = n, i = 0, j = 0; len>0; len-=2){
            //if(len == 1)  ans[i][j] = cnt++;
            // else{

                // draw up line
                while(j < n - offset ) ans[i][j++] = cnt++;
                // draw down line
                while(i < n - offset ) ans[i++][j] = cnt++;

                while(j >= offset) ans[i][j--] = cnt++;

                while(i >= offset) ans[i--][j] = cnt++;
                i++; j++; offset++;
                
            //}
        }
        return ans;
    }
};
// @lc code=end


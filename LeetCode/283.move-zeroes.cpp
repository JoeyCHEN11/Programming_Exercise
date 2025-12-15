/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0; 
        for(int fast = 0; fast < nums.size(); fast ++ ){
            if(nums[fast] != 0) nums[slow++] = nums[fast];
        }
        while(slow < nums.size()) nums[slow++] = 0;
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto last = remove(nums.begin(),nums.end(),val);
        
        //auto last = nums.begin();
        // for(auto fast = nums.begin(); fast != nums.end(); fast++){
        //     if(val != *fast){
        //         *last++ = *fast;
        //         //last ++;    
        //     }            
        // }

        return distance(nums.begin(),last);
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
#include <cmath>

class Solution {
public:

    int mySqrt(int x) {
        long long left = 0, right = (long long)x + 1,mid = 0;
        while(left < right){
            mid = left + (right - left)/2;
            if(mid * mid <= x)left = mid + 1;
            else right = mid;
        }
        return right - 1;
    }
};
// @lc code=end


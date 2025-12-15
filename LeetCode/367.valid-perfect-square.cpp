/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 0, right = (long long)num + 1,mid = 0;
        while(left < right){
            mid = left + (right - left)/2;
            if(mid * mid < num)left = mid + 1;
            else if(mid * mid > num) right = mid;
            else return true;
        }
        return false;
    }
};
// @lc code=end


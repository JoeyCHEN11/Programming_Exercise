/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    const int INF = 1e5 + 1;
    int minSubArrayLen_bi(int target, vector<int>& nums){
        int n = nums.size();
        if(n==0) return 0;
        vector<int> acsum (n+1);

        acsum[0] = 0;
        for(int i = 1; i <= n; i ++){
            acsum[i] = nums[i-1] + acsum[i-1];
            
        }
        
        //length [0,n]
        int left = 0, right = n;
        int mid_len;

        while(left<=right){
            mid_len = (left + right)/2;
            bool flag = false; 
            for(int i = mid_len; i <= n; i ++){
                if(acsum[i] - acsum[i-mid_len] >= target){
                    flag = true;
                    break;
                }
            }

            if(flag){
                right = mid_len - 1;
            }else{
                left = mid_len + 1;
            }

        }
        return right==n? 0:right+1;
    }

    int minSubArrayLen_sliding_windows(int target, vector<int>& nums){
        int min_len = __INT32_MAX__;
        int sum = 0;
        int n = nums.size();
        for(int i = 0,j = 0; i < n; i++){
            sum += nums[i];
            
            while(sum>=target) {
                min_len = min(min_len, i - j + 1);
                sum -= nums[j++];
            }
        }
        return min_len==__INT32_MAX__? 0:min_len;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        return minSubArrayLen_sliding_windows(target,nums);

    }
};
// @lc code=end


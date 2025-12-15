/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // void merge_square(vector<int> & neg, vector<int> & pos, vector<int> & nums){

    // }
    const int INF = 1e9;
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans (n);
        // stack<int> neg;

        // vector<int>::iterator idx;
        // nums.push_back(INF);
        // neg.push(INF);
        // for(idx = nums.begin(); *idx<0; idx++) neg.push(-*idx);

        // int top;
        // for(int i = 0; i < ans.size(); i++){
        //     if(neg.top() < *idx){
        //         top = neg.top();neg.pop();
        //         ans[i] = top * top;
        //     }else{
        //         ans[i] = *idx * *idx;
        //         idx++;
        //     }
        // }

        //直接逆序归并（第一个非负数正好为数组的两半部分提供了下界）
        for(int i = 0, j = n - 1, pos = n - 1; pos >= 0; pos--){
            if(nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                i++;
            }
            else {
                ans[pos] = nums[j] * nums[j];
                j--;
            }
        }
        return ans;

    }
};
// @lc code=end


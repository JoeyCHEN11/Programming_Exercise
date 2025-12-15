/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (66.78%)
 * Likes:    16719
 * Dislikes: 843
 * Total Accepted:    2.2M
 * Total Submissions: 3.3M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 * 
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 * 
 * Can you solve it without sorting?
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

#include <functional>
#include <queue>
#include <utility>
#include <vector>
#include <cstdlib>
#include <ctime>
// @lc code=start
using namespace std;

/**
 * @brief find kth largest element
 * 
 */
class KLargest{
public:
    KLargest() { srand(time(nullptr)); }
    int partition(vector<int>& nums, int p, int r){
        bool eqFlag = true;
        swap(nums[rand() % (r - p + 1) + p], nums[r]);
        int x = nums[r];
        int i = p - 1;
        for(int j = p; j < r; j++){
            if(nums[j] <= x) {
                if(nums[j] == x){
                    eqFlag = !eqFlag;
                    if(!eqFlag) continue;
                }
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[r]);
        return i;
    }

    pair<int, int> threePartition(vector<int>& nums, int p, int r){
        swap(nums[rand() % (r - p + 1) + p], nums[p]);
        int x = nums[p];
        int i = p, h = p;
        for(int j = p + 1; j <= r; j++){
            if(nums[j] < x) {
                swap(nums[++h], nums[j]);
                swap(nums[i++], nums[h]);
            }else if(nums[j] == x){
                swap(nums[++h], nums[j]);
            }
        }
        //swap(nums[++h], nums[r]);
        return {i, h};
    }

    //借用快排的快速选择，进行了简单的随机化和三路划分，期望复杂度为O(n)
    int quickSelect(vector<int>& nums, int k, int left, int right){
        //检测k是否符合条件
        //if(nums.size() < k) return quickSelect(nums, nums.size(), left, right);
        //      != ok
        if(left < right){
            auto [pivotL, pivorR] = threePartition(nums, left, right);
            //cout<<"left: "<<left<<", right:" <<right<<", p:"<<pivot<<endl;
            //cout<<"distance: "<< nums.size() - pivot<<endl;
            if(nums.size() - pivotL < k) return quickSelect(nums, k, left, pivotL - 1);
            if(nums.size() - pivorR > k) return quickSelect(nums, k, pivorR + 1, right);
            else return nums[pivotL];
        }
        return nums[nums.size() - k];
    }

    //k最小堆，O(k + nlogk), 建k大小的最小堆，对堆进行最多n次调整，或由于k不大于n，可理解为O(nlogn)
    //不会改变原数组
    int stableKLargest(const vector<int>& nums, int k){
        int n = nums.size();
        if(n < k) k = n;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);

        for(int i = k; i < n; i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.emplace(nums[i]);
            }
        }
        return pq.top();
    }
};

class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        KLargest kl;
        return kl.quickSelect(nums, k, 0, nums.size() - 1);
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (62.72%)
 * Likes:    16735
 * Dislikes: 618
 * Total Accepted:    1.9M
 * Total Submissions: 3.1M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 * 
 * 
 * 
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <functional> //std::greater<T>

using namespace std;
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //                  cnt, num                           min heap (default: less<T> (max heap))
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        int n = nums.size();

        // sort(nums.begin(), nums.end());
        // int cnt = 1;
        // for(int i = 1; i <= n; i++){
        //     if(i < n && nums[i] == nums[i - 1]) cnt++;
        //     else {   
        //         if(pq.size() >= k && pq.top().first < cnt) pq.pop();
        //         if(pq.size() < k) pq.push({cnt, nums[i - 1]});
        //         cnt = 1;
        //     }
        // }


        //count using map
        unordered_map<int, int> check;
        for(int a : nums) check[a]++;
        //     C++17 structed binding
        for(auto [num, count] : check){
            if(pq.size() >= k && (pq.top().first) < count) pq.pop();
            if(pq.size() < k) pq.emplace(count, num);
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end


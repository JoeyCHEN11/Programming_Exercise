/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (46.53%)
 * Likes:    17677
 * Dislikes: 636
 * Total Accepted:    970.2K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * You are given an array of integers nums, there is a sliding window of size k
 * which is moving from the very left of the array to the very right. You can
 * only see the k numbers in the window. Each time the sliding window moves
 * right by one position.
 * 
 * Return the max sliding window.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation: 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <set>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        
        // binary tree (set) O(nlogn)
        // multiset<int> max_set;
        // int n = nums.size();
        // int i = 0;
        // for(int j = 0; j < n; j++){
        //     if(j >= k) max_set.erase(max_set.find(-nums[i++]));
        //     max_set.insert(-nums[j]);
        //     if(j >= k - 1) ans.push_back(-*max_set.begin());
        // }

        //monotonic queue O(n)
        deque<int> m_dq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(!m_dq.empty() && m_dq.back() < nums[i]) m_dq.pop_back();
            m_dq.push_back(nums[i]);
            if(i >= k && m_dq.front() == nums[i - k]) m_dq.pop_front();
            if(i >= k - 1) ans.push_back(m_dq.front());
        }

        return ans;
    }
};
// @lc code=end


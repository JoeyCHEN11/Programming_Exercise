/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start

#include <vector>
#include <unordered_map>;
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int max_fruits = -__INT32_MAX__;
        int n = fruits.size();
        unordered_map<int,int> cnt;

        for(int i = 0,j = 0; i < n; i++){
            cnt[fruits[i]]++;
            while(cnt.size()>2){
                cnt[fruits[j]]--;
                if(cnt[fruits[j]]==0) cnt.erase(fruits[j]);
                j++;
            }
            max_fruits = max(max_fruits,i-j+1);
        }
        return max_fruits;
    }
};
// @lc code=end


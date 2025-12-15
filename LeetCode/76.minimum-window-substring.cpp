/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <cstdint>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char,int> t_check;
        for(char c:t) t_check[c]++;
        
        int t_cnt = n;
        pair<int,int> begin_len = {0,INT32_MAX};


        for(int i = 0,j = 0; j < m; j++){
            auto c_in_t = t_check.find(s[j]);
            //traverse s
            if(c_in_t!=t_check.end()){//if current char is in t
                
                //corresponding counter -1
                c_in_t->second--;
                //total counter -1 (if the window is still not acceptable)
                if(c_in_t->second>=0) t_cnt--;

                //if the current window is acceptable, shrink the window
                //       == 0 ok
                if(t_cnt <= 0){
                    for(auto c = t_check.find(s[i]); c==t_check.end() || c->second < 0 ;c = t_check.find(s[i])){  
                        if(c!=t_check.end()) c->second++;
                        i++;
                    }

                    // update min window
                    if(begin_len.second > j - i + 1)
                        begin_len = {i,j - i + 1};
                }
            }

        }

        return begin_len.second == INT32_MAX? "" : s.substr(begin_len.first,begin_len.second);
    }
};
// @lc code=end


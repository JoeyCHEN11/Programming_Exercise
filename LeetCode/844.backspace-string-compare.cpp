/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:

    int remove_backspace(string & s){
        int slow = 0;
        for(int fast = 0; fast < s.size(); fast++){
            if(s[fast] != '#') s[slow++] = s[fast];
            else if(slow>0) slow--;
        }
        return slow;
    }
    bool backspaceCompare(string s, string t) {
        int s_end = remove_backspace(s);
        int t_end = remove_backspace(t);
        if(s_end == t_end && s.substr(0,s_end) == t.substr(0,t_end)) return true;
        else return false;
        
    }
};
// @lc code=end


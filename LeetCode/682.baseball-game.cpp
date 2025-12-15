/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 *
 * https://leetcode.com/problems/baseball-game/description/
 *
 * algorithms
 * Easy (76.04%)
 * Likes:    2773
 * Dislikes: 1891
 * Total Accepted:    344K
 * Total Submissions: 452K
 * Testcase Example:  '["5","2","C","D","+"]'
 *
 * You are keeping the scores for a baseball game with strange rules. At the
 * beginning of the game, you start with an empty record.
 * 
 * You are given a list of strings operations, where operations[i] is the i^th
 * operation you must apply to the record and is one of the following:
 * 
 * 
 * An integer x.
 * 
 * 
 * Record a new score of x.
 * 
 * 
 * '+'.
 * 
 * Record a new score that is the sum of the previous two scores.
 * 
 * 
 * 'D'.
 * 
 * Record a new score that is the double of the previous score.
 * 
 * 
 * 'C'.
 * 
 * Invalidate the previous score, removing it from the record.
 * 
 * 
 * 
 * 
 * Return the sum of all the scores on the record after applying all the
 * operations.
 * 
 * The test cases are generated such that the answer and all intermediate
 * calculations fit in a 32-bit integer and that all operations are valid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ops = ["5","2","C","D","+"]
 * Output: 30
 * Explanation:
 * "5" - Add 5 to the record, record is now [5].
 * "2" - Add 2 to the record, record is now [5, 2].
 * "C" - Invalidate and remove the previous score, record is now [5].
 * "D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
 * "+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
 * The total sum is 5 + 10 + 15 = 30.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ops = ["5","-2","4","C","D","9","+","+"]
 * Output: 27
 * Explanation:
 * "5" - Add 5 to the record, record is now [5].
 * "-2" - Add -2 to the record, record is now [5, -2].
 * "4" - Add 4 to the record, record is now [5, -2, 4].
 * "C" - Invalidate and remove the previous score, record is now [5, -2].
 * "D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
 * "9" - Add 9 to the record, record is now [5, -2, -4, 9].
 * "+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
 * "+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
 * The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ops = ["1","C"]
 * Output: 0
 * Explanation:
 * "1" - Add 1 to the record, record is now [1].
 * "C" - Invalidate and remove the previous score, record is now [].
 * Since the record is empty, the total sum is 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= operations.length <= 1000
 * operations[i] is "C", "D", "+", or a string representing an integer in the
 * range [-3 * 10^4, 3 * 10^4].
 * For operation "+", there will always be at least two previous scores on the
 * record.
 * For operations "C" and "D", there will always be at least one previous score
 * on the record.
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        for(auto s : operations){
            char op = s[0];
            if(op == '+'){
                record.push_back(*(record.end() - 2) + record.back());
            }else if(op == 'D'){
                record.push_back(record.back() * 2);
            }else if(op == 'C'){
                record.pop_back();
            }else{
                record.emplace_back(stoi(s));
            } 
        }
        return accumulate(record.begin(), record.end(), 0);
    }
};
// @lc code=end


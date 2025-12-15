/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 *
 * https://leetcode.com/problems/car-pooling/description/
 *
 * algorithms
 * Medium (56.09%)
 * Likes:    4395
 * Dislikes: 93
 * Total Accepted:    217.1K
 * Total Submissions: 387.1K
 * Testcase Example:  '[[2,1,5],[3,3,7]]\n4'
 *
 * There is a car with capacity empty seats. The vehicle only drives east
 * (i.e., it cannot turn around and drive west).
 * 
 * You are given the integer capacity and an array trips where trips[i] =
 * [numPassengersi, fromi, toi] indicates that the i^th trip has numPassengersi
 * passengers and the locations to pick them up and drop them off are fromi and
 * toi respectively. The locations are given as the number of kilometers due
 * east from the car's initial location.
 * 
 * Return true if it is possible to pick up and drop off all passengers for all
 * the given trips, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 4
 * Output: false
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 5
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= trips.length <= 1000
 * trips[i].length == 3
 * 1 <= numPassengersi <= 100
 * 0 <= fromi < toi <= 1000
 * 1 <= capacity <= 10^5
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int N = 1000 + 1;
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        // Brute Force O(n^2)
        // vector<int> road(N, capacity);
        // for(auto & trip : trips){
        //     int numP = trip[0];
        //     for(int i = trip[1]; i < trip[2]; i++){
        //         road[i] -= numP;
        //         if(road[i] < 0) return false;
        //     }
        // }
        // return true;     

        // difference array
        int maxN = max_element(trips.begin(), trips.end(),
         [](const auto & t1, const auto & t2) 
                -> bool { return t1[2] < t2[2]; })->at(2);
        vector<int> diff(maxN + 1, 0);

        // add elements between [from, to)
        for_each(trips.begin(), trips.end(),
        [& diff](auto & trip) -> void {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        });

        int cnt = 0;
        for(int d : diff) {
            cnt += d;
            if(cnt > capacity) return false;
        }
        return true;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 *
 * https://leetcode.com/problems/snakes-and-ladders/description/
 *
 * algorithms
 * Medium (43.82%)
 * Likes:    2824
 * Dislikes: 965
 * Total Accepted:    180.8K
 * Total Submissions: 412.6K
 * Testcase Example:  '[[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]'
 *
 * You are given an n x n integer matrix board where the cells are labeled from
 * 1 to n^2 in a Boustrophedon style starting from the bottom left of the board
 * (i.e. board[n - 1][0]) and alternating direction each row.
 * 
 * You start on square 1 of the board. In each move, starting from square curr,
 * do the following:
 * 
 * 
 * Choose a destination square next with a label in the range [curr + 1,
 * min(curr + 6, n^2)].
 * 
 * 
 * This choice simulates the result of a standard 6-sided die roll: i.e., there
 * are always at most 6 destinations, regardless of the size of the
 * board.
 * 
 * 
 * If next has a snake or ladder, you must move to the destination of that
 * snake or ladder. Otherwise, you move to next.
 * The game ends when you reach the square n^2.
 * 
 * 
 * A board square on row r and column c has a snake or ladder if board[r][c] !=
 * -1. The destination of that snake or ladder is board[r][c]. Squares 1 and
 * n^2 do not have a snake or ladder.
 * 
 * Note that you only take a snake or ladder at most once per move. If the
 * destination to a snake or ladder is the start of another snake or ladder,
 * you do not follow the subsequent snake or ladder.
 * 
 * 
 * For example, suppose the board is [[-1,4],[-1,3]], and on the first move,
 * your destination square is 2. You follow the ladder to square 3, but do not
 * follow the subsequent ladder to 4.
 * 
 * 
 * Return the least number of moves required to reach the square n^2. If it is
 * not possible to reach the square, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
 * Output: 4
 * Explanation: 
 * In the beginning, you start at square 1 (at row 5, column 0).
 * You decide to move to square 2 and must take the ladder to square 15.
 * You then decide to move to square 17 and must take the snake to square 13.
 * You then decide to move to square 14 and must take the ladder to square 35.
 * You then decide to move to square 36, ending the game.
 * This is the lowest possible number of moves to reach the last square, so
 * return 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [[-1,-1],[-1,3]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == board.length == board[i].length
 * 2 <= n <= 20
 * board[i][j] is either -1 or in the range [1, n^2].
 * The squares labeled 1 and n^2 do not have any ladders or snakes.
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int n, n2;
    int ans, cnt;
    vector<int> visited;
    vector<int> d;
    pair<int, int> getPos(int id){
        //n is odd
        int i = n - 1 - ((id - 1) / n);
        int j;
        if(n & 1){
            j = i & 1? n - 1 - ((id - 1) % n) : (id - 1) % n;
        }else{
            j = i & 1? (id - 1) % n : n - 1 - ((id - 1) % n);
        } 
        //cout<<i<<" "<<j<<endl;
        return {i, j};
    }

    void climbBFS(int r, vector<vector<int>>& board){
        queue<int> que;
        que.emplace(r);
        visited[r] = true;
        d[r] = 0;

        while(!que.empty()){
            int u = que.front(); que.pop();

            for(int step = 1; step <= 6; step++){
                int next = u + step;
                if(next > n2) break;
                auto [i, j] = getPos(next);

                int v = board[i][j] == -1? next : board[i][j];
                if(!visited[v]){
                    que.emplace(v);
                    visited[v] = true;
                    d[v] = d[u] + 1;
                }
            }
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        n2 = n * n;
        ans = INT32_MAX;
        cnt = 0;
        visited.resize(n2 + 1, false);
        d.resize(n2 + 1, INT32_MAX);
        climbBFS(1, board);
        return d[n2] == INT32_MAX? -1 : d[n2];
    }
};
// @lc code=end


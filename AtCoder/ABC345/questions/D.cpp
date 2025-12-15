#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool tiling(int height, int weight, vector<pair<int, int>> & tiles){
    vector<vector<bool>> dp(height + 1, vector<bool>(weight + 1, false));
    dp[0][0] = true;
    for(auto [h, w] : tiles){
        int n = min(w, h);
        for(int i = height; i >= n; i--){
            for(int j = weight; j >= n; j--){
                if(j >= w && i >= h) dp[i][j] = dp[i][j] | (dp[i - h][j - w] & dp[i - h][j] & dp[i][j - w]);

                if(j >= h && i >= w) dp[i][j] = dp[i][j] | (dp[i - w][j - h] & dp[i - w][j] & dp[i][j - h]);
            }
        }
    }
    return dp[height][weight];
}

int main(){
    int n, height, weight, h, w;
    vector<pair<int, int>> tiles;
    cin>>n>>height>>weight;
    while(n--){
        cin>>h>>w;
        tiles.emplace_back(h, w);
    }
    cout<<(tiling(height, weight, tiles) ? "Yes" : "No")<<endl;
    
}
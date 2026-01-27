#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static const int MAXSIZE = 1500;

int init(vector<vector<int>>& dp, const vector<vector<int>> & m){
    int h = m.size(), w = m[0].size();
    int init_max = 0;
    for(int i = 0; i < w; i++) {
        dp[0][i] = !m[0][i]? 1:0;
        init_max |= dp[0][i];
    }
    for(int i = 0; i < h; i++) {
        dp[i][0] = !m[i][0]? 1:0;
        init_max |= dp[i][0];
    }
    return init_max;
}

int largest_square(vector<vector<int>>& m){
    int h = m.size();
    int w = m[0].size();
    vector<vector<int>> dp(h, vector<int>(w));
    
    int max_side = init(dp, m);
    for(int i = 1; i < h; i++){
        for(int j = 1; j < w; j++){
            if(m[i][j]) dp[i][j] = 0;
            else{
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                max_side = max(dp[i][j], max_side); 
            }
        }
    }
    // cout<<endl;
    // for(auto & v:dp){
    //     for(auto & tile:v){
    //         cout<<tile<<" ";
    //     }
    //     cout<<endl;
    // }
    return max_side * max_side;
}




int main(int argc, char const *argv[])
{
    int height, weight;
    cin>>height>>weight;
    vector<vector<int>> m(height,vector<int>(weight));
    for(auto & v:m){
        for(auto & tile:v){
            cin>>tile;
        }
    }

    cout<<largest_square(m)<<endl;

    return 0;
}

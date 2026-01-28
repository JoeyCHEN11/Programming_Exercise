#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct rect{
    int left;
    int height;
};

void init(vector<vector<int>>& dp, const vector<vector<int>> & m){
    int h = m.size(), w = m[0].size();
    dp.resize(h, vector<int>(w + 1));
    int init_max = 0;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(m[i][j]) dp[i][j] = 0;
            else dp[i][j] = i > 0? dp[i - 1][j] + 1 : 1;
        }
        dp[i][w] = 0;
    }
}

//O(hw)
//栈中存入还有可能增长的矩形    
int largest_rectangle(vector<vector<int>>& m){
    int h = m.size();
    int w = m[0].size();
    int max_rect = 0;
    vector<vector<int>> dp_height;
    init(dp_height, m);

    stack<rect> rect_s;
    rect_s.push({-1, 0});
    for(int i = 0; i < h; i++){
        for(int j = 0; j <= w; j++){
            rect new_rect = {j, dp_height[i][j]};
                               // <= ok but not necessary
            while(new_rect.height < rect_s.top().height){
                max_rect = max(max_rect, (j - rect_s.top().left) * rect_s.top().height);
                new_rect.left = rect_s.top().left;
                rect_s.pop();
            }
            if(new_rect.height > rect_s.top().height){
                rect_s.push(new_rect);
            }
        }
    }

    return max_rect;
}

int main(int argc, char const *argv[])
{
    int height, weight;
    cin>>height>>weight;
    vector<vector<int>> m(height,vector<int>(weight));

    for(auto& v : m) for(int& c : v) cin>>c;

    cout<<largest_rectangle(m)<<endl;

    return 0;
}

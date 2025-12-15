#include <bits/stdc++.h>

using namespace std;

int h, w;
int cnt = 0;

vector<string> grid;

vector<vector<pair<int, int>>> root;

int dir[4][2] {-1, 0, 0, 1, 1, 0, 0, -1};

bool boundCheck(int i, int j){
    return i >= 0 && i < h && j >=0 && j < w;
}
bool isfree(int i, int j){
    for(auto [dx, dy] : dir){
        if(boundCheck(i + dx, j + dy) && grid[i + dx][j + dy] == '#') return false;
    }
    return true;
}

void dfs (pair<int, int> r, int ui, int uj){
    if(root[ui][uj] == r) return;
    root[ui][uj] = r;

    if(grid[ui][uj] == '#') return;
    cnt++;
    if(isfree(ui, uj)){
        for(auto [dx, dy] : dir){
            // cout<<"check v"<<endl;
            int vi = dx + ui;
            int vj = dy + uj;
            // cout<<vi<<' '<<vj<<endl;
            if(boundCheck(vi, vj)) dfs(r, vi, vj);
        }
    }
}

int gerMaxDegree(){
    int ans = 0;
    for(int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) {
            if(root[i][j].first == -1 && root[i][j].second == -1) {
                cnt = 0;
                dfs({i, j}, i, j);
                ans = max(ans, cnt);
            }
        }
    }
    return ans;
}

int main(){
    cin>>h>>w;
    grid.resize(h);
    root.resize(h, vector<pair<int, int>>(w, {-1, -1}));
    for(auto & s : grid) cin>>s;
    //for(auto s : grid) cout<<s;
    cout<<gerMaxDegree()<<endl;
}
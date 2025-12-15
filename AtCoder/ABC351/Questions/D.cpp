#include <bits/stdc++.h>

using namespace std;

int h, w;
int cnt = 0;

vector<string> grid;
        //              root from dfs
vector<vector<pair<int, int>>> root;
pair<int, int> nil {-1, -1};

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
    // if(root[ui][uj] == r) return;
    root[ui][uj] = r;

    cnt++;
    if(isfree(ui, uj)){
        for(auto [dx, dy] : dir){
            // cout<<"check v"<<endl;
            int vi = dx + ui;
            int vj = dy + uj;
            // cout<<vi<<' '<<vj<<endl;
            if(boundCheck(vi, vj) && 
            grid[vi][vj] == '.' && 
            //跳过所有本次已访问的节点避免重复计算，但上一次dfs访问过的root不同的节点，需要再这次计算时再次访问，算入度
            root[vi][vj] != r) dfs(r, vi, vj);
        }
    }
}

/**
 * @brief 当 有一条边s->s' 时，有两种情况
 *          1. s' 周围有#，则s'的度为1，必有degree(s) > degree(s')
 *          2. s' 周围没有#，则s与s'双向连通，则：s与s'的度完全相同
 *          因此，一个点作为root进行dfs后，其经过的所有点都无需再作为起点进行dfs计算度
 * @return int 
 */
int gerMaxDegree(){
    int ans = 0;
    for(int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) {
            if(grid[i][j] == '.' && root[i][j]== nil) {
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
#include <bits/stdc++.h>

using namespace std;

static const int BLOCK = -1;
static const int EMPTY = 0;

int dir[4][2] { 0, -1, -1, 0, 0, 1, 1, 0};
pair<int, int> start;
pair<int, int> target;
vector<vector<int>> grid;
int m, n, medNum, maxE;
bool boundCheck(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }

bool bfs(){
    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(maxE + 1, false)));
    //          i,   j,  energy
    queue<tuple<int, int, int>> que;
    auto [ri, rj] = start;
    int re = grid[ri][rj];
    visited[ri][rj][re] = true;
    que.emplace(ri, rj, re);

    while(!que.empty()){
        auto [ui, uj, ue] = que.front(); que.pop();
        // cout<<"ui: "<<ui<<", uj: "<<uj<<", ue: "<<ue<<endl;

        if(ui == target.first && uj == target.second) return true;

        if(ue > 0){
            for(auto [dx, dy] : dir){
                int vi = ui + dx;
                int vj = uj + dy;
                if(boundCheck(vi, vj) && grid[vi][vj] != BLOCK){
                    int ve;
                    if(grid[vi][vj] == EMPTY){
                        ve = ue - 1;
                        if(!visited[vi][vj][ve]){
                            visited[vi][vj][ve] = true;
                            que.emplace(vi, vj, ve);
                        }
                    }else{
                        ve = grid[vi][vj];
                        if(!visited[vi][vj][ue - 1]){
                            visited[vi][vj][ue - 1] = true;
                            que.emplace(vi, vj, ue - 1);
                        }
                        if(!visited[vi][vj][ve]){
                            visited[vi][vj][ve] = true;
                            que.emplace(vi, vj, ve);
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main(){
    cin>>m>>n;
    grid.resize(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin>>c;
            if(c == 'S') start = {i, j};
            if(c == 'T') target = {i, j};
            if(c == '#') grid[i][j] = BLOCK;
            if(c == '.') grid[i][j] = EMPTY;
        }
    }

    cin>>medNum;
    maxE = 0;
    for(int e = 0; e < medNum; e++){
        int i, j;
        cin>>i>>j;
        cin>>grid[i - 1][j - 1];
        maxE = max(maxE, grid[i - 1][j - 1]);
    }

    cout<<(bfs()? "Yes" : "No")<<endl;

}


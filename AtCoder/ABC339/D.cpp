#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> grid;
vector<pair<int, int>> players;

int dir[4][2] { -1, 0, 0, 1, 1, 0, 0, -1};

bool boundCheck(int i, int j){
    return i < n && i >= 0 && j < n && j >= 0;
}

int bfs(){
    auto [p1i, p1j] = players[0];
    auto [p2i, p2j] = players[1];
    // p1i, p1j, p2i, p2j
    vector steps(n, vector(n, vector(n, vector(n, -1))));
    steps[p1i][p1j][p2i][p2j] = 0;
    // cout<<"player 1: "<<p1i<<" "<<p1j<<", player 2: "<<p2i<<" "<<p2j<<endl;
    queue<tuple<int, int, int, int>> que;
    que.emplace(p1i, p1j, p2i, p2j);

    while(!que.empty()){
        auto [u1i, u1j, u2i, u2j] = que.front(); que.pop();

        if(u1i == u2i && u1j == u2j) return steps[u1i][u1j][u2i][u2j];
        // cout<<"player 1: "<<u1i<<" "<<u1j<<", player 2: "<<u2i<<" "<<u2j<<endl;
        for(auto [dx, dy] : dir){
            int v1i = u1i + dx;
            int v1j = u1j + dy;
            int v2i = u2i + dx;
            int v2j = u2j + dy;
            if(!boundCheck(v1i, v1j) || grid[v1i][v1j] == '#'){
                v1i = u1i;
                v1j = u1j;
            }
            if(!boundCheck(v2i, v2j) || grid[v2i][v2j] == '#'){
                v2i = u2i;
                v2j = u2j;
            }
            if(steps[v1i][v1j][v2i][v2j] == -1){
                que.emplace(v1i, v1j, v2i, v2j);
                steps[v1i][v1j][v2i][v2j] = steps[u1i][u1j][u2i][u2j] + 1;
            }
        }
    }
    return -1;
}

void init(){
    cin>>n;
    grid.resize(n);
    for(auto & s : grid) {
        cin>>s;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 'P') players.emplace_back(i, j);
        }
    }
}

int main(){
    init();
    cout<<bfs()<<endl;
}
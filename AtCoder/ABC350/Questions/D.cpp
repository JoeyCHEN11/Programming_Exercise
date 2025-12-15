#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
//          node#, edge#
// vector<pair<int, int>> comps;

pair<int, int> bfs(int r){
    int nodeNum = 1, edgeNum = 0;
    queue<int> que;
    visited[r] = true;
    que.emplace(r);

    while(!que.empty()){
        int u = que.front(); que.pop();

        for(auto v : graph[u]){
            edgeNum++;
            if(!visited[v]){
                nodeNum++;
                visited[v] = true;
                que.emplace(v);
            }
        }
    }

    return {nodeNum, edgeNum / 2};
}
int howManyOps(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            auto [nodeNum, edgeNum] = bfs(i);
            ans += (nodeNum * (nodeNum - 1)) / 2 - edgeNum;
        }
    }
    return ans;
}


int main(){
    cin>>n>>m;
    graph.clear();
    visited.clear();
    // comps.clear();
    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    cout<<howManyOps()<<'\n';
}



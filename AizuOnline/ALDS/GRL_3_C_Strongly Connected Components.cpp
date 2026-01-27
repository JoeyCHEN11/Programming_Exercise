#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <set>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> gtrans;
// color, check for gtrans
vector<int> components;
// check
vector<bool> visited;
list<int> topo;
int n, e;
int color = 0;



void topoSort(){
    auto topoDfs = [](auto& dfs, int u) -> void {
        visited[u] = true;
        for(int v : graph[u]){
            if(!visited[v]) dfs(dfs, v);
        }
        topo.push_front(u); 
    };

    for(int i = 0; i < n; i++){
        if(!visited[i]) topoDfs(topoDfs, i);
    }
}


void getScc(){
    
    topoSort();

    auto sccDfs = [](const auto & dfs, int u) -> void {
        components[u] = color;
        for(int v : gtrans[u]){
            if(!components[v]) dfs(dfs, v);
        }
    };

    for(int u : topo){
        if(!components[u]){
            color++;
            sccDfs(sccDfs, u);
        }
    }
}

int main(int argc, char const *argv[])
{
    int s, t;
    cin>>n>>e;
    graph.resize(n);
    gtrans.resize(n);
    visited.resize(n, false);
    components.resize(n, 0);

    for(int i = 0; i < e; i ++){
        cin>>s>>t;
        graph[s].push_back(t);
        gtrans[t].push_back(s);
    }
    getScc();

    int u, v, q;
    cin>>q;
    //for(auto c : components) cout<<c<<" ";
    while(q--){
        cin>>u>>v;
        cout<<(components[u] == components[v]? 1 : 0)<<endl;
    }

    return 0;
}

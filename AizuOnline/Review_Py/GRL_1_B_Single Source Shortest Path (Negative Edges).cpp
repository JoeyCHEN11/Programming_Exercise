#include <bits/stdc++.h>

using namespace std;

int n, e;
static const int INF = INT32_MAX;
vector<vector<pair<int,int>>> graph;
vector<int> parents;
vector<int> distances; 


bool bellman(int s){
    distances[s] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int u = 0; u < n; u++){
            for(auto [v, w] : graph[u]){

                if( distances[u] != INF &&
                    distances[v] > distances[u] + w ){
                    distances[v] = distances[u] + w;
                    parents[v] = u;
                }
            }
        }
    }

    for(int u = 0; u < n; u++){
        for(auto [v, w] : graph[u]){
            if( distances[u] != INF &&
                distances[v] > distances[u] + w){
                return false;
            }
        }
    }
    return true; 
}

int main(){
    int s;
    cin>>n>>e>>s;
    graph.resize(n);
    parents.resize(n, -1);
    distances.resize(n, INF);
    while(e--){
        int s, t, w;
        cin>>s>>t>>w;
        graph[s].emplace_back(t, w);
    }

    if(bellman(s)){
        for(auto d : distances) cout<<(d == INF? "INF": to_string(d))<<endl;
    }else cout<<"NEGATIVE CYCLE"<<endl;
}
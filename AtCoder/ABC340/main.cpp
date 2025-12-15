#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

        //         w,     v;
vector<vector<pair<ull, int>>> graph;
vector<ull> distances;
int n;

ull dijk(int r){
    priority_queue<pair<ull, int>, vector<pair<ull, int>>, greater<pair<ull, int>>> pq;
    pq.emplace(0, r);
    distances[r] = 0;

    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();

        if(d > distances[u]) continue;

        for(auto [w, v] : graph[u]){
            if(w + d < distances[v]){
                distances[v] = w + d;
                pq.emplace(w + d, v); 
            }

        }
    }

    return distances[n - 1];
}

void init(){
    cin>>n;
    graph.resize(n);
    distances.resize(n);
    for(int i = 0; i < n - 1; i++){
        int a, b, x;
        cin>>a>>b>>x;
        graph[i].emplace_back(a, i + 1);
        graph[i].emplace_back(b, x - 1);
    }
    for(auto & d : distances) d = ULLONG_MAX;
}

int main(){
    init();
    cout<<dijk(0)<<endl;
}

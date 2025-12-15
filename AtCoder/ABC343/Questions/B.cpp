#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> graph;

int main(){
    cin>>n;
    graph.resize(n, vector<int>(n, 0));

    for(auto& vec : graph){
        for(auto& e : vec){
            cin>>e;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j]) cout<<j + 1<<' ';
        }
        cout<<endl;
    }
}
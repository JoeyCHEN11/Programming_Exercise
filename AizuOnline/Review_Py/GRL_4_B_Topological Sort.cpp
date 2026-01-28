#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <list>

using namespace std;

static const int MAXV = 1e5 + 1;
static const int MAXE = 1e5 + 1;

enum status {WHITE, GRAY, BLACK};

int in_deg[MAXV];
bool is_sorted[MAXV];
vector<int> G[MAXV];
list<int> ans;

void init(int v){
    for (int i = 0; i < v; i++) in_deg[i] = 0;
    for (int i = 0; i < v; i++){
        is_sorted[i] = false;
        for (int j = 0; j < G[i].size(); j++){
            in_deg[G[i][j]]++;
        }
    }
}

void topo_dfs(int u){
    is_sorted[u] = true;
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(!is_sorted[v]) topo_dfs(v);
    }
    ans.push_front(u);
}

void topo_bfs(int r){
    queue<int> topo_queue;
    is_sorted[r] = true;
    ans.push_back(r);
    topo_queue.push(r);

    while(!topo_queue.empty()){
        int u = topo_queue.front(); topo_queue.pop();

        for (int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            in_deg[v]--;
            if(in_deg[v] == 0){
                is_sorted[v] = true;
                ans.push_back(v);
                topo_queue.push(v);
            }
        }
    }
}

void topo_sort(int v){
    init(v);
    
    for(int i = 0; i < v; i++){

        //bfs
        if(in_deg[i] == 0 && !is_sorted[i]) topo_bfs(i);
        //dfs
        //if(!is_sorted[i]) topo_dfs(i); 
    }
}



int main(int argc, char const *argv[])
{
    int v,e,s,t;
    cin>>v>>e;
    init(v);

    for(int i = 0; i < e; i ++){
        cin>>s>>t;
        G[s].push_back(t);
    }

    topo_sort(v);

    for(int a: ans) cout<<a<<endl;

    return 0;
}

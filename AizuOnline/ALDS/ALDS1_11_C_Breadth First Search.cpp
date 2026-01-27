#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 100;
int G[MAXN][MAXN] = {0};

queue<int> BFS_Queue;
int distances[MAXN];
int n;

void init(){
    for(int i = 0; i < n; i++) distances[i] = -1;
}



void bfs_visit(int r){

    init();
    distances[r] = 0;
    
    BFS_Queue.push(r);
    while(!BFS_Queue.empty()){
        int u = BFS_Queue.front(); BFS_Queue.pop();
        for(int v = 0; v<n; v++){
            if(G[u][v]&&distances[v]==-1){
                distances[v] = distances[u]+1;
                BFS_Queue.push(v);
            }
        }
    }
}


int main(){
    int u,k,v;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>u>>k;
        for(int j = 0; j < k; j++){
            cin>>v;
            G[u-1][v-1] = 1;
        }
    }

    bfs_visit(0);
    for(int i = 0; i < n ; i++){
        cout<<i+1<<" "<<distances[i]<<endl;
    }
}  
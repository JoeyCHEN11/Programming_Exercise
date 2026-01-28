#include <iostream>

using namespace std;

const int MAXN = 100;
const int INF = ((unsigned)1<<31) - 1 ;
enum status {WHITE, GRAY, BLACK};
status color[MAXN];
int G[MAXN][MAXN];
int d_to_s[MAXN];
int parent[MAXN];


void init(int n){
    for(int i = 0; i < n; i++) {
        color[i] = WHITE;
        d_to_s[i] = INF;
        parent[i] = -1;
        for(int j = 0; j < n; j++) G[i][j] = INF;
    }
}

void dijkstra(int s, int n){
    
    // start from 0
    d_to_s[s] = 0;
    parent[s] = -1;
    color[s] = GRAY;
    int weight_sum = 0;
    int u,mincost;
    while(true){
        
        mincost = INF;
        for(int i = 0; i < n; i++){
            //          == GRAY better
            if(color[i] != BLACK && d_to_s[i] < mincost){
                mincost = d_to_s[i];
                u = i;
            }
        }
        if(mincost == INF) break;

        
        color[u] = BLACK;
        //weight_sum += mincost;

        //mark u's adjacent as V-T nodes (GRAY), update d_to_s for possible shorter edges
        for(int i = 0; i < n; i++){
            if(color[i] != BLACK && G[u][i] != INF){
                if(G[u][i] + d_to_s[u] < d_to_s[i]){
                    d_to_s[i] = G[u][i] + d_to_s[u];
                    parent[i] = u;
                    color[i] = GRAY;
                }
            }
        }
    }
}



int main(){
    int n,u,k,v;

    cin>>n;
    init(n);

    for(int i = 0; i < n; i++){
        cin>>u>>k;
        for(int j = 0; j < k; j++){
            cin>>v;
            cin>>G[u][v];
        }
    }
    
    dijkstra(0, n);

    for(int i = 0; i < n; i ++){
        if(d_to_s[i]!=INF) cout<<i<<" "<<d_to_s[i]<<endl;
    }
    
}  
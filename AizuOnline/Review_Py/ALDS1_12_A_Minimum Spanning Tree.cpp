#include <iostream>

using namespace std;

const int MAXN = 100;
const int INF = 1<<30;
enum status {WHITE, GRAY, BLACK};
status color[MAXN];
int G[MAXN][MAXN];
    //distance to tree
int d_to_T[MAXN];
int parent[MAXN];


void init(int n){
    for(int i = 0; i < n; i++) {
        color[i] = WHITE;
        d_to_T[i] = INF;
        parent[i] = -1;
    }
}

int prim(int n){
    init(n);
    // start from 0
    d_to_T[0] = 0;
    parent[0] = -1;
    color[0] = GRAY;
    int weight_sum = 0;
    int u,mincost;
    while(true){
        
        //find new u node from V-T (GRAY) nodes
        mincost = INF;
        for(int i = 0; i < n; i++){
            //          == GRAY better
            if(color[i] != BLACK && d_to_T[i] < mincost){
                mincost = d_to_T[i];
                u = i;
            }
        }
        if(mincost == INF) break;

        
        color[u] = BLACK;
        //weight_sum += mincost;

        //mark u's adjacent as V-T nodes (GRAY), update d_to_T for possible shorter edges
        for(int i = 0; i < n; i++){
            if(color[i] != BLACK && G[u][i] < d_to_T[i]){
                d_to_T[i] = G[u][i];
                parent[i] = u;
                color[i] = GRAY;
            }
        }
    }
    for(int i = 0; i<n; i++) weight_sum += d_to_T[i] == INF? 0:d_to_T[i];
    return weight_sum;
}



int main(){
    int n;

    cin>>n;
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>G[i][j];
            if(G[i][j]==-1) G[i][j] = INF;
        }
    }

    cout<<prim(n)<<endl;
    
}  
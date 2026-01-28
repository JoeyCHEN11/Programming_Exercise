#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;

static const ll INF = LLONG_MAX;
static const int MAXV = 100;
static const int MAXE = 1e4;

ll G[MAXV + 1][MAXV + 1];

void init(int v){
    for(int i = 1; i <= v; i ++){
        for(int j = 1; j <= v; j++){
             G[i][j] = i == j? 0:INF;
        }
    }
}


// find shortest path in a directed weighted graph containing negative weights
// dynamic programming A(k)[i, j]: the shortest path from i-j only pass through nodes {1,2,3,...,k}
// can  traverse all possible paths
bool warshall_floyd(int v){
    for (int k = 1; k <= v; k++){
        for (int i = 1; i <= v; i++){
            if(G[i][k] == INF || i == k) continue;
            for (int j = 1; j <= v; j++){
                if(G[k][j] == INF || j == k) continue;
                else G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }            
        }
    }
    for(int i = 1; i <= v; i++) if(G[i][i] < 0) return false;
    return true;
}


int main(int argc, char const *argv[])
{
    int v,e,s,t;
    cin>>v>>e;
    init(v);

    for(int i = 0; i < e; i ++){
        cin>>s>>t;
        cin>>G[s+1][t+1];
    }

    if(warshall_floyd(v)){
        for (int i = 1; i <= v; i++){
            for (int j = 1; j <= v; j++){
                cout<<(G[i][j] == INF? "INF":to_string(G[i][j]));
                if(j<v) cout<<" ";
            }
            cout<<endl;
        }
    }else cout<<"NEGATIVE CYCLE"<<endl;

    return 0;
}

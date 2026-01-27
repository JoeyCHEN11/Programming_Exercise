#include <iostream>
#include <climits>
#include <vector>
#include <queue>


using namespace std;

static const int MAXV = 1e5 + 1;
static const int INF = INT_MAX;
static const int N_INF = INT_MIN;
    

enum status {WHITE, GRAY, BLACK};

vector<pair<int,int>> G[MAXV];
int d_to_r[MAXV];

void init_d(int n){
    for (int i = 0; i < n; i++) d_to_r[i] = N_INF;
}


void find_distance_bfs(int n, int r){
    init_d(n);
    queue<int> bfs;
    bfs.push(r);
    d_to_r[r] = 0;

    while(!bfs.empty()){
        int u = bfs.front(); bfs.pop();
        for(int i = 0; i < G[u].size(); i++){
            auto p = G[u][i];
            if(d_to_r[p.first] == N_INF) {
                d_to_r[p.first] = p.second + d_to_r[u];
                bfs.push(p.first);
            }
        }
    }
}

int find_diameter(int n){
    find_distance_bfs(n,0);

    int max_d = N_INF;
    int max_v = 0;
    for (int i = 1; i < n; i++){
        if(d_to_r[i] > max_d){
            max_v = i;
            max_d = d_to_r[i];
        }
    }

    max_d = N_INF;
    find_distance_bfs(n,max_v);
    for(int d: d_to_r) max_d = max(d,max_d);

    return max_d==N_INF? 0:max_d;
}


int main(int argc, char const *argv[])
{
    int n,s,t,w;
    cin>>n;

    for(int i = 0; i < n - 1; i ++){
        cin>>s>>t>>w;
        G[s].push_back(make_pair(t,w));
        G[t].push_back(make_pair(s,w));
    }

    cout<<find_diameter(n)<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int MAXN = 1e4;
const int INF = ((unsigned)1<<31) - 1 ;
enum status {WHITE, GRAY, BLACK};
status color[MAXN];
vector<pair<int, int>> G[MAXN]; //edge(u,v) int G[u][i] => <v,weight>
int d_to_s[MAXN];
int parent[MAXN];


void init(int n){
    for(int i = 0; i < n; i++) {
        color[i] = WHITE;
        d_to_s[i] = INF;
        parent[i] = -1;
    }
}

/*
test: 
5
0 2 2 1 1 5
1 1 4 2
2 1 3 2
3 2 1 1 4 6
4 0
*/
void dijkstra(int s){
    priority_queue<pair<int, int>> min_heap;

    // start from 0
    d_to_s[s] = 0;
    parent[0] = -1;
    color[0] = GRAY;
    int weight_sum = 0;
    min_heap.push(make_pair(0,0));
    int u,mincost;
    while(!min_heap.empty()){
        
        
        auto f= min_heap.top(); min_heap.pop();
        u = f.second;
        
        // color[u] == BLACK ok
        // d_to_s[u] != -f.first ok
        if(d_to_s[u] < -f.first) continue;
        color[u] = BLACK;

        //mark u's adjacent as V-T nodes (GRAY), update d_to_T for possible shorter edges
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].first;
            int c = G[u][i].second;
            if(color[v] != BLACK){
                if(c + d_to_s[u] < d_to_s[v]){
                    d_to_s[v] = c + d_to_s[u];
                    parent[v] = u;
                    color[v] = GRAY;
                    min_heap.push(make_pair(-d_to_s[v],v));
                }
            }
        }
    }
}

void show_path(int n){
    stack<pair<int, int>> path;
    cout<<"path from 0"<<" to "<<n<<": "<<endl;
    cout<<0;
    int d = n;
    int p = parent[d];
    //path.push(make_pair(d,d_to_s[d] - d_to_s[p]));

    while (p!=-1){
        path.push(make_pair(d,d_to_s[d] - d_to_s[p]));
        d = p;
        p = parent[d];
    }

    while(!path.empty()){
        auto node = path.top(); path.pop();
        cout<<"--("<<node.second<<")-->"<<node.first;
    }
    cout<<" total:"<<d_to_s[n]<<endl;
}


int main(){
    int n,u,k,v,c;

    cin>>n;
    init(n);

    for(int i = 0; i < n; i++){
        cin>>u>>k;
        for(int j = 0; j < k; j++){
            cin>>v>>c;
            G[u].push_back(make_pair(v,c));
            
        }
    }
    
    dijkstra(0);

    for(int i = 0; i < n; i ++){
        if(d_to_s[i]!=INF) cout<<i<<" "<<d_to_s[i]<<endl;
    }

    //for(int i = 0; i < n; i++) show_path(i);
    
}  
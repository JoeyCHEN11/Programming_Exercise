#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

static const int MAXV = 1e5 + 1;

enum color {WHITE, GRAY, BLACK};

int pre_num[MAXV];
int parent[MAXV];
//lowest[u]: 从u出发，经过其子树和其子树包含的后向边能回到的最早节点的对应的时间戳（回溯最早时间）
int lowest[MAXV];
bool visited[MAXV];
int next_check[MAXV];
vector<int> G[MAXV];
set<int> ans;



void init(int n){
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        next_check[i] = -1;
        parent[i] = -1;
    }

}

int find_next(int u){
    next_check[u]++;
    int next_v = next_check[u];
    return next_v >= G[u].size()? -1 : G[u][next_v];
}

void dfs(int r){
    int timer = 1;
    stack<int> dfs;
    
    dfs.push(r);
    visited[r] = true;
    lowest[r] = pre_num[r] = timer++;


    while(!dfs.empty()){
        int u = dfs.top();
    
        int v = find_next(u);
        if(v!=-1){
            if(!visited[v]){ //tree edge
                visited[v] = true;
                lowest[v] = pre_num[v] = timer++;
                parent[v] = u;
                dfs.push(v);
            }else if(v != parent[u]){ //back edge
                //cout<<"get back edge"<<endl;
                lowest[u] = min(lowest[u], pre_num[v]);
            }
        }else{//end visit
            //update u's parnet's lowest (except it is a root)
            if(u!=r){
                int p = parent[u];
                lowest[p] = min(lowest[p], lowest[u]);
            }
            dfs.pop();
        }
    }
}


void find_articulation(int r, int n, set<int> & ans){
    dfs(r);

    int r_child = 0;
    for(int i = 0; i < n; i++){
        if(i == r) continue;

        int p = parent[i];
        if(p == r) r_child++;
        //
        //也就是说，确定了当前节点想要访问其任意更早的时间戳对应的节点（祖先），必须经过其父节点 <==> 其父节点唯一地连通了两个不相通的子图 <==> 父节点为关节点 
        else if(pre_num[p] <= lowest[i]) ans.insert(p);
    }
    if(r_child>1) ans.insert(r);
}


int main(int argc, char const *argv[])
{
    int n,e,s,t;
    cin>>n>>e;
    init(n);

    for(int i = 0; i < e; i ++){
        cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    find_articulation(0,n,ans);

    for(int a: ans) cout<<a<<endl;

    return 0;
}

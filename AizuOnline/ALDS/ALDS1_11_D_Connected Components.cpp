#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 1e5;
vector<int> G[MAXN];

queue<int> BFS_Q;
stack<int> DFS_S;
int next_check[MAXN];
int groups[MAXN];
int NIL = -1;

void init(int n){
    for(int i = 0; i < n; i++) groups[i] = NIL;
    for(int i = 0; i < n; i++) next_check[i] = 0;
}


int find_next(int u){
    int next_v = next_check[u]; 
    if(next_v < G[u].size()) {
        next_check[u] ++;
        return G[u][next_v]; 
    }
    else return -1;
}

void bfs_visit(int r, int g){
    BFS_Q.push(r);
    groups[r] = g;
    //cout<<"bfs from: "<<r<<endl;
    while(!BFS_Q.empty()){
        int u = BFS_Q.front(); BFS_Q.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            if(groups[v]==NIL){
                //cout<<v<<" ";
                groups[v] = g;
                BFS_Q.push(v);
            }
        }
    }
    
}


void dfs_visit(int r, int g){
    
    DFS_S.push(r);
    groups[r] = g;
    //cout<<"dfs from: "<<r<<endl;
    while(!DFS_S.empty()){
        int u = DFS_S.top();
        int next_v = find_next(u);
        if(next_v==-1){
            DFS_S.pop();
        }else if(groups[next_v]==NIL){
            //cout<<next_v<<" ";
            groups[next_v] = g;
            DFS_S.push(next_v);
        }
    }
}

void dfs_solution(int r, int g){
    DFS_S.push(r);
    groups[r] = g;
    //cout<<"dfs from: "<<r<<endl;
    while(!DFS_S.empty()){
        int u = DFS_S.top(); DFS_S.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            if(groups[v]==NIL){
                //cout<<v<<" ";
                groups[v] = g;
                DFS_S.push(v);
            }
        }
    }
    //cout<<endl;
}

void dfs_solution_strict(int r, int g){
    DFS_S.push(r);
    //groups[r] = g;
    //cout<<"dfs from: "<<r<<endl;
    while(!DFS_S.empty()){
        int u = DFS_S.top(); DFS_S.pop();
        if(groups[u]==NIL){
            groups[u] = g;
            //cout<<"visit: "<<u<<endl;
            for(int i = 0; i < G[u].size(); i++){
                int v = G[u][i];
                
                if(groups[v]==NIL) {
                    //cout<<"push node: "<<v<<endl;
                    DFS_S.push(v);
                }
            }
        }else{
            //cout<<u<<" already visited"<<endl;
        }
    }
    //cout<<endl;
}

void divide_group(int n){
    init(n);
    int g = 0;
    for(int i = 0; i < n; i ++){
        if(groups[i]==NIL) dfs_visit(i,g++);
        //if(groups[i]==NIL) bfs_visit(i,g++);
        //if(groups[i]==NIL) dfs_solution(i,g++);
        //if(groups[i]==NIL) dfs_solution_strict(i,g++);

    }
}

int main(){
    int u,v,n,m,q;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }

    divide_group(n);
    cin>>q;
    for(int i = 0; i < q ; i++){
        cin>>u>>v;
        cout<<(groups[u] == groups[v]? "yes":"no")<<endl;
    }
}  
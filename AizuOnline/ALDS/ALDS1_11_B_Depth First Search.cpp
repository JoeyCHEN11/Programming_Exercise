#include <iostream>
#include <stack>

using namespace std;
enum status {WHITE, GRAY, BLACK};//unvisited, visiting, visited

const int MAXN = 100;
int G[MAXN][MAXN] = {0};

stack< pair<int,int> > DFS_Stack;
int d[MAXN]={0}, f[MAXN] = {0};
status node_status[MAXN] = {WHITE};
int n,time_slot;

int find_next(){
    for(auto top_node = DFS_Stack.top(); top_node.second<n; top_node.second++){
        DFS_Stack.top().second = top_node.second + 1;
        if(G[top_node.first][top_node.second]!=0) return top_node.second;
    }
    //if node has no adjacent nodes
    return -1;
}

void dfs_visit_iter(int u){
    DFS_Stack.push(make_pair(u,0));
    node_status[u] = GRAY;
    d[u] = ++time_slot;
    while(!DFS_Stack.empty()){
        
        //cout<<"now visit:"<<top_node.first<<endl;

        // for(auto top_node = DFS.top(); top_node.second<=n; top_node = DFS.top()){
        //     if(G[top_node.first][top_node.second]!=0 && d[top_node.second] == 0){
        //        // cout<<"find "<<top_node.second<<endl;
        //         d[top_node.second] = ++time_slot;
        //         DFS.top().second++;
        //         DFS.push(make_pair(top_node.second,1));
        //         break;
        //     } else{
        //         DFS.top().second++;
        //     }
        // }


        int next_v = find_next();
        if(next_v!=-1){
            if(node_status[next_v] == WHITE){
                d[next_v] = ++time_slot;
                node_status[next_v] = GRAY;
                DFS_Stack.push(make_pair(next_v,0));
            }
        }else{
            //cout<<"finish node:"<<fin_node<<endl;
            f[DFS_Stack.top().first] = ++time_slot;
            node_status[DFS_Stack.top().first] = BLACK;
            DFS_Stack.pop();
        }
    }
}

void dfs_visit_rec(int u){
    node_status[u] = GRAY;
    d[u] = ++time_slot;
    for(int i = 0; i<n; i++){
        if(G[u][i] && node_status[i] == WHITE){
            dfs_visit_rec(i);
        }
    }
    node_status[u] = BLACK;
    f[u] = ++time_slot;
}

void dfs(){
    time_slot = 0;
    for(int i = 0; i < n; i++){
        if(node_status[i]==WHITE) {
            dfs_visit_iter(i);
            //dfs_visit_rec(i);
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
    dfs();
    for(int i = 0; i < n ; i++){
        cout<<i+1<<" "<<d[i]<<" "<<f[i]<<endl;
    }

}
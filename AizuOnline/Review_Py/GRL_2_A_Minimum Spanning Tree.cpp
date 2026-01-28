#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#include <algorithm>


using namespace std;

static const int MAXE = 1e5 + 1;

vector<vector<pair<int, int>>> graph;
vector<int> distances;
vector<bool> visited;

class Edge{    
public:
    int v_out,v_in,w;
    bool operator<(const Edge & e) const { return w < e.w; }
    Edge(int _out = 0, int _in = 0, int _w = 0): v_out(_out), v_in(_in), w(_w) {};
};

class Disjoint_Set{
private:
    vector<int> rank, forest;

    void link_tree(int x, int y){
        if(rank[x]<rank[y]) forest[x] = forest[y];
        else {
            if(rank[x]==rank[y]) rank[x]++; 
            forest[y] = forest[x];
        }
    }

public:
    Disjoint_Set(int n){
        rank.resize(n,0);
        forest.resize(n,0);
        for(int i = 0; i < n; i++) make_set(i);
    }

    void make_set(int x){
        forest[x] = x;
        rank[x] = 0;
    }

    void unite(int x, int y){
        link_tree(find_set(x),find_set(y));
    }

    int find_set(int x){
        if(forest[x]!=x) forest[x] = find_set(forest[x]);        
        return forest[x];
    }

    int find_set_iter(int x){
        int p = forest[x];
        vector<int> children(1,x);
        while(p!=forest[p]){
            children.push_back(p);
            p = forest[p];
        }
        for(int c : children) forest[c] = p;
        return p;
    }

    bool same(int x, int y) { return find_set(x)==find_set(y);}
};


int kruskal(vector<Edge>& edges ){
    Disjoint_Set ds(edges.size()+1);
    int ans = 0;

    sort(edges.begin(), edges.end());
    
    for (auto e : edges){
        if(!ds.same(e.v_out, e.v_in)){
            ans += e.w;
            ds.unite(e.v_out,e.v_in);
        }
    }

    return ans;
}

int primPQ(int r){
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>> pq;
    // distances to tree;
    distances[r] = 0;
    // visited[r] = true;
    pq.emplace(0, r);

    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();

        if(visited[u]) continue;

        ans += d;
        // cout<<"pick:"<<u<<" , d:"<<d<<endl;
        // set black
        visited[u] = true;


        for(auto [w, v] : graph[u]){
            //与dijkstra不同，prim必须设置一个bool位判断是否已经结束访问，否则存在重复判断
            //如：从u选中了v, (u, v)，w = 2, 而u已经是T的一部分，且mst中连接u的一条边是3，则2会重复再记入（当下次选中v，会返回遇到u，重新pick一次u）
            if(!visited[v] && distances[v] > w){
                distances[v] = w;
                pq.emplace(w, v);
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int v_n,e_n,s,t,w;
    vector<Edge> edges;
    
    cin>>v_n>>e_n;

    //for prim
    graph.resize(v_n);
    distances.resize(v_n, INT32_MAX);
    visited.resize(v_n, false);

    for(int i = 0; i < e_n; i ++){
        cin>>s>>t>>w;

        //build graph for prim
        graph[s].emplace_back(w, t);
        graph[t].emplace_back(w, s);

        edges.push_back(Edge(s,t,w));
    }

    cout<<primPQ(0)<<endl;
    // cout<<kruskal(edges)<<endl;
    return 0;
}

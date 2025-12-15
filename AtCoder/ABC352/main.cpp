#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> rank, forest;
    int setNum;

public:
    DisjointSet(int n){
        setNum = n;
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

    void link_tree(int x, int y){
        if(x == y) return;
        if(rank[x]<rank[y]) forest[x] = forest[y];
        else {
            if(rank[x]==rank[y]) rank[x]++; 
            forest[y] = forest[x];
        }
        setNum--;
    }

    int find_set(int x){
        if(forest[x]!=x) forest[x] = find_set(forest[x]);
        return forest[x];
    }

    bool same(int x, int y) { return find_set(x)==find_set(y);}
    int getSetNum() { return setNum; }

    ~DisjointSet(){}
};

using ll = long long;
struct Edge{
    int c;
    vector<int> vertx;
    bool operator <(const Edge& e) const { return c < e.c; }
};

int n, m;
vector<Edge> edges;

ll buildMST(){
    ll ans = 0;
    sort(edges.begin(), edges.end());
    DisjointSet ds(n + 1);

    for(auto & e : edges){
        int k = e.vertx.size();
        for(int i = 1; i < k; i++){
            int u = e.vertx[i - 1];
            int v = e.vertx[i];
            if(!ds.same(u, v)) {
                ds.unite(u, v);
                ans += e.c;
            }
        }
    }

    return ds.getSetNum() == 2? ans : -1;

}

int main(){
    cin>>n>>m;

    edges.resize(m);
    for(Edge & e: edges){
        int k;
        cin>>k>>e.c;
        e.vertx.resize(k);
        for(int& u : e.vertx) cin>>u;
    }

    cout<<buildMST()<<endl;

}
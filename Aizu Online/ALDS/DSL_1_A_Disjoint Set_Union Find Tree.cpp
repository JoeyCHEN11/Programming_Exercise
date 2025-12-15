#include <iostream>
#include <vector>

using namespace std;

class Disjoint_Set
{
private:
    vector<int> rank, forest;
    int setNum;
public:

    Disjoint_Set(int n){
        rank.resize(n,0);
        forest.resize(n,0);
        setNum = n;
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

    ~Disjoint_Set(){}
};

int main(int argc, char const *argv[])
{
    int n,q,com,x,y;
    cin>>n>>q;
    Disjoint_Set ds(n);
    for(int i = 0; i < q; i++){
        cin>>com>>x>>y;
        if(com == 0) ds.unite(x,y);
        else printf("%d\n",ds.same(x,y));
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




class Node
{
public:
    //index of the point in the sorted points acoording to x-y partition
    int idx;
    //index of its children in the tree
    int left, right;
};

class Point
{
public:
    
    int id, x, y;

    bool operator < (const Point & p) const {
        return id < p.id;
    }
    Point():x(0), y(0){};
    Point(int _x, int _y):x(_x), y(_y){}

    void print(){
        printf("%d\n", id);
    }
};

bool comp_x( const Point & p1, const Point & p2){ return p1.x < p2.x; }
bool comp_y(const Point & p1, const Point & p2){ return p1.y < p2.y; }

static const int MAXN = 5e5 + 1;
static const int NIL = -1;

Node kd_tree[MAXN];
Point points[MAXN];

int node_idx = 0;
int make_2d_tree(int left, int right, int depth){
    if(left >= right) return NIL;

    if(depth % 2 == 0) sort(points + left , points + right, comp_x);
    else sort(points + left, points + right, comp_y);

    int mid = (left + right)/2;
    int t_idx = node_idx++;

    kd_tree[t_idx].idx = mid;
    kd_tree[t_idx].left = make_2d_tree(left, mid, depth + 1);
    kd_tree[t_idx].right = make_2d_tree(mid + 1, right, depth + 1);

    return t_idx;
}

void find_in_kdtree(int v,int sx,int tx,int sy,int ty, int depth, vector<Point> & ans){
    const Node & node = kd_tree[v];
    const Point & point =  points[node.idx];
    int x = point.x;
    int y = point.y;

    if(sx <= x && x <= tx && sy <= y && y <= ty) ans.push_back(point);

    //here is x-level, check x
    if(depth % 2 == 0){
        if(node.left != NIL && point.x >= sx) find_in_kdtree(node.left, sx, tx, sy, ty, depth + 1, ans);
        if(node.right != NIL && point.x <= tx) find_in_kdtree(node.right, sx, tx, sy, ty, depth + 1, ans);
    }else{
        if(node.left != NIL && point.y >= sy) find_in_kdtree(node.left, sx, tx, sy, ty, depth + 1, ans);
        if(node.right != NIL && point.y <= ty) find_in_kdtree(node.right, sx, tx, sy, ty, depth + 1, ans);
    }
}


int main(int argc, char const *argv[])
{
    int n,q;
    int sx, tx, sy, ty; 
    vector<Point> ans;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&points[i].x, &points[i].y);

        points[i].id = i;
    }

    int root = make_2d_tree(0,n,0);

    cin>>q;
    for(int i = 0; i < q; i++){
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        find_in_kdtree(root,sx,tx,sy,ty,0,ans);
        sort(ans.begin(), ans.end());
        for(auto p : ans) p.print();
        printf("\n");
        ans.clear();
    }
    return 0;
}


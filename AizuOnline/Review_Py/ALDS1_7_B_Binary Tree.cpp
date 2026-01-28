#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXSIZE = 25;
const int MAXV = 1e4;

//
struct Node{ int parent, left_child, right_child; };

Node Nodes[MAXSIZE];
int Depths[MAXSIZE];
int Heights[MAXSIZE];
int NIL = -1;

void set_depths(int u, int d){
    Depths[u] = d;
    if(Nodes[u].left_child!=NIL) set_depths(Nodes[u].left_child, d+1);
    if(Nodes[u].right_child!=NIL) set_depths(Nodes[u].right_child, d+1);
}

int set_heights(int u){
    
    //left subtree's height +1 (if no subtree, be 0)
    int h1 = 0;
    //right ...
    int h2 = 0;

    if(Nodes[u].left_child!=NIL) h1 = set_heights(Nodes[u].left_child) + 1;
    if(Nodes[u].right_child!=NIL) h2 = set_heights(Nodes[u].right_child) + 1;
    return Heights[u] = max(h2,h1);
}

int get_degree(int u){
    if(Nodes[u].left_child!=NIL && Nodes[u].right_child!=NIL) return 2;
    else if(Nodes[u].left_child==NIL && Nodes[u].right_child==NIL) return 0;
    else return 1;
}

int get_sibling(int u){
    if(Nodes[u].parent == NIL) return NIL;
    else {
        int parent = Nodes[u].parent;
        return Nodes[parent].left_child == u ? Nodes[parent].right_child : Nodes[parent].left_child;
    }
}

string get_type(int u){
    if(Nodes[u].parent == NIL) return "root";
    else if(Nodes[u].left_child == NIL && Nodes[u].right_child == NIL) return "leaf";
    else return "internal node";
}

int main(){
    int n,root,u,left,right;
    cin>>n;
    for(int i = 0; i < n; i++) Nodes[i].left_child = Nodes[i].parent = Nodes[i].right_child = NIL;

    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&u,&left,&right);
        if(left != NIL){
            Nodes[u].left_child = left;
            Nodes[left].parent = u;
        }
        if(right != NIL){
            Nodes[u].right_child = right;
            Nodes[right].parent = u;
        }
    } 
    for(int i = 0; i<n; i ++) {
        if(Nodes[i].parent == NIL) {
            root = i;
            break;
        }
    }
    set_depths(root, 0);
    set_heights(root);
    for(int i = 0; i<n; i++){
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
            i,Nodes[i].parent, get_sibling(i),get_degree(i),Depths[i],Heights[i],get_type(i).c_str());
    }
}
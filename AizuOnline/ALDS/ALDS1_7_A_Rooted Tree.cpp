#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXSIZE = 1e5;
const int MAXV = 1e4;

//left-child right-sibling representation
struct Node{ int parent, left_child, right_sibling; };

Node Nodes[MAXSIZE];
int Depths[MAXSIZE];
int NIL = -1;

void setdepths(int u, int d){
    Depths[u] = d;
    if(Nodes[u].left_child!=NIL) setdepths(Nodes[u].left_child, d+1);
    if(Nodes[u].right_sibling!=NIL) setdepths(Nodes[u].right_sibling, d);
}

int get_depth(int u){
    int ans = 0;
    for(int c = Nodes[u].parent; c!=NIL; c = Nodes[c].parent){
        ans ++;
    }
    return ans;
}

void println_children(int u){
    printf("[");
    for(int child = Nodes[u].left_child; child != NIL; child = Nodes[child].right_sibling){
        printf("%d",child);
        if(Nodes[child].right_sibling!=-1) printf(", ");
    }
    printf("]\n");
}

string get_type(int u){
    if(Nodes[u].parent == NIL) return "root";
    else if(Nodes[u].left_child == NIL) return "leaf";
    else return "internal node";
}

int main(){
    int n,u,k,c,c_left_sibling,root;
    cin>>n;
    for(int i = 0; i < n; i++) Nodes[i].left_child = Nodes[i].parent = Nodes[i].right_sibling = NIL;

    for(int i = 0; i < n; i++){
        scanf("%d %d",&u,&k);
        
        //read children
        // if(k>0) {
        //     scanf("%d",&c);
        //     Nodes[u].left_child = c;
        //     Nodes[c].parent = u;
        //     k--;
        //     for(int j = 0; j<k; j++){
        //         scanf("%d",&Nodes[c].right_sibling);
        //         c = Nodes[c].right_sibling;
        //         Nodes[c].parent = u;
        //     }
        // }

        //read children (more readable)
        for(int j = 0; j < k; j++){
            //read current child
            scanf("%d",&c);
            //set the child as u's left child (if it is c0) or its left sibiling's right
            if(j == 0) Nodes[u].left_child = c;
            else Nodes[c_left_sibling].right_sibling = c;
            //set current child's parent as u
            Nodes[c].parent = u;
            c_left_sibling = c;
        }
    } 
    for(int i = 0; i<n; i ++) {
        if(Nodes[i].parent == NIL) {
            root = i;
            break;
        }
    }
    setdepths(root, 0);
    for(int i = 0; i<n; i++){
        printf("node %d: parent = %d, depth = %d, %s, ", i, Nodes[i].parent,Depths[i], get_type(i).c_str());
        println_children(i);
    }
}
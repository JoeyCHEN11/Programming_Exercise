#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXSIZE = 25;
const int MAXV = 1e4;

//
struct Node{ int parent, left_child, right_child; };

Node Nodes[MAXSIZE];
int NIL = -1;

void preorder_walk(int u){
    if(u==-1) return;
    cout<<" "<<u;
    preorder_walk(Nodes[u].left_child);
    preorder_walk(Nodes[u].right_child);
}

void inorder_walk(int u){
    if(u==-1) return;
    inorder_walk(Nodes[u].left_child);
    cout<<" "<<u;
    inorder_walk(Nodes[u].right_child);
}

void postorder_walk(int u){
    if(u==-1) return;
    postorder_walk(Nodes[u].left_child);
    postorder_walk(Nodes[u].right_child);
    cout<<" "<<u;
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
    cout<<"Preorder"<<endl;
    preorder_walk(root);
    cout<<endl<<"Inorder"<<endl;
    inorder_walk(root);
    cout<<endl<<"Postorder"<<endl;
    postorder_walk(root);
    cout<<endl;
}
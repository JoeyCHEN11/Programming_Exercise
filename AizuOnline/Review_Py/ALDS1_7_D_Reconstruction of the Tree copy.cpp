#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXSIZE = 100;
const int MAXV = 1e4;
//Hard problem

struct Node{ int parent, left_child, right_child; };

Node Nodes[MAXSIZE+1];
vector<int> pre, in,post;
int NIL = -1;
int n, counter = 0;
vector<int>::iterator pre_pos; 


void postorder_walk(int u){
    if(u==-1) return;
    postorder_walk(Nodes[u].left_child);
    postorder_walk(Nodes[u].right_child);
    cout<<" "<<u;
}



//reconstruct the tree [left_bound,right_bound)
int reconstruct(int left_bound,int right_bound){
    //no elements, which implies that the root on the previous level has no corresponding sub-tree
    if(left_bound>=right_bound) return -1;
    //counter++;

    //get the root by traversing the pre sequence
    int root = *pre_pos;
    pre_pos++;

    //get the index of the root in inorder sequence
    int root_idx_in = distance(in.begin(), find(in.begin(),in.end(),root));
    //because of the feature of inorder sequense, its left sub-tree is located at the left of root
    //reconstruct left sub-tree
    Nodes[root].left_child = reconstruct(left_bound,root_idx_in);
    //reconstruct right sub-tree
    Nodes[root].right_child = reconstruct(root_idx_in+1,right_bound);
    post.push_back(root);
    return root;
}


int main(){
    int root,u;
    cin>>n;
    for(int i = 0; i < n; i++) Nodes[i].left_child = Nodes[i].parent = Nodes[i].right_child = NIL;
    for(int i = 0; i < n; i++){
        cin>>u;
        pre.push_back(u);
    } 
    for(int i = 0; i<n; i ++) {
        cin>>u;
        in.push_back(u);
    }
    pre_pos = pre.begin();
    //cout<<*pre_pos;
    reconstruct(0,n);
    for(int i = 0; i<n; i ++) {
        if(i)cout<<" ";
        cout<<post[i];
    }
    cout<<endl;
    
    //cout<<counter;
    //postorder_walk(*pre.begin());
}
#include <iostream>
#include <algorithm>
#include <cstdio>
typedef long long llong;
using namespace std;


struct Node{ 
    llong key; 
    Node *parent, *left, *right;
};

Node *NIL, *root;

void preorder_walk(Node * u){
    if(u==NIL) return;
    printf(" %d",(u->key));
    preorder_walk(u->left);
    preorder_walk(u->right);
}

void inorder_walk(Node * u){
    if(u==NIL) return;
    inorder_walk(u->left);
    printf(" %d",(u->key));
    inorder_walk(u->right);
}

void insert(llong key){
    Node * new_node = new Node;
    new_node->left = NIL;
    new_node->right = NIL;
    new_node->key = key;

    Node * current = root;
    Node * insert_p = NIL;
    while(current!=NIL){
        insert_p = current;
        current = key<current->key? current->left:current->right; 
    }
    new_node->parent = insert_p;
    if(insert_p == NIL) root = new_node;
    else if(key < insert_p->key) insert_p->left = new_node;
    else insert_p->right = new_node;
}

void print_tree(){
    inorder_walk(root);
    cout<<endl;
    preorder_walk(root);
    cout<<endl;
}

int main(){

    int m;
    char command[10];
    llong k;
    cin>>m;

    for(int i = 0; i < m; i++){
        scanf("%s",command);
        if(command[0] == 'i'){
            scanf("%lld",&k);
            insert(k);
        }
        else print_tree();
    }
}
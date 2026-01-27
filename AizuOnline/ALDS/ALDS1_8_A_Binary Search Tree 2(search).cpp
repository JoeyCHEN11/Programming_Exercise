#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

//
struct Node{ 
    int key; 
    Node *parent, *left, *right;
};

Node *root;

void preorder_walk(Node * u){
    if(u==nullptr) return;
    printf(" %d",(u->key));
    preorder_walk(u->left);
    preorder_walk(u->right);
}

void inorder_walk(Node * u){
    if(u==nullptr) return;
    inorder_walk(u->left);
    printf(" %d",(u->key));
    inorder_walk(u->right);
}

void insert(int key){
    Node * new_node = new Node;
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->key = key;

    Node * current = root;
    Node * insert_p = nullptr;
    while(current!=nullptr){
        insert_p = current;
        current = key<current->key? current->left:current->right; 
    }
    new_node->parent = insert_p;
    if(insert_p == nullptr) root = new_node;
    else if(key < insert_p->key) insert_p->left = new_node;
    else insert_p->right = new_node;
}

Node * find(int key){
    Node * current = root;
    while(current!=nullptr && current->key!=key){
        if(key < current->key) current = current->left;
        else current = current->right;
    }
    return current;
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
    int k;
    cin>>m;

    for(int i = 0; i < m; i++){
        scanf("%s",command);
        if(command[0] == 'i'){
            scanf("%d",&k);
            insert(k);
        }
        else if(command[0] == 'f'){
            scanf("%d",&k);
            if(find(k)!=nullptr) printf("yes\n");
            else printf("no\n");
        } 
        else print_tree();
    }
}
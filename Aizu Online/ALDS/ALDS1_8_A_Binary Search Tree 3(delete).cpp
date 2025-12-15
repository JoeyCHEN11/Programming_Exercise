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

Node * find_node(int key){
    Node * current = root;
    while(current!=nullptr && current->key!=key){
        if(key < current->key) current = current->left;
        else current = current->right;
    }
    return current;
}


// my answer
// /**
//  * @brief find the next of u in inorder, u must have an right subtree
//  * 
//  * @param u 
//  * @return Node* 
//  */
// Node * find_next(Node* u){
//     Node* current = u->right;
//     while(current->left != nullptr) current = current->left;
//     return current;
// }

// void delete_node(Node* node){
//     if(node==nullptr) return;
//     if(node->left==nullptr && node->right==nullptr) {
//         if(node->key < node->parent->key) node->parent->left = nullptr;            
//         else node->parent->right = nullptr;
//         delete node;
//     }
//     else if(node->left != nullptr && node->right == nullptr){
//         node->left->parent = node->parent;
//         if(node!=root){
//             if(node->key < node->parent->key) node->parent->left = node->left;            
//             else node->parent->right = node->left;
            
//         }else{
//             node->right->parent = nullptr;
//             root = node->parent;
//         } 
//         delete node;

//     }else if(node->left == nullptr && node->right != nullptr){
//         if(node!=root){
//             node->right->parent = node->parent;
//             if(node->key < node->parent->key) node->parent->left = node->right;
//             else node->parent->right = node->right;
//         } else {
//             node->right->parent = nullptr;
//             root = node->right;
//         }
//         delete node;
//     }else{
//         Node * candidate = get_successor(node);
//         node->key = candidate->key;
//         delete_node(candidate);
//     }
// }

//more readable solution

//more compatible version of find_next, although the else part is useless in this problem
Node* get_successor(Node* u){
    if(u->right!=nullptr){
        Node* current = u->right;
        while(current->left != nullptr) current = current->left;
        return current;
    }else{
        Node* current = u->parent;
        while(current!=nullptr && current->left != u ) {
            u = current;
            current = current->parent;
        }
        return current;
    }
}

void delete_node(Node* node){
    if(node==nullptr) return;
    
    Node * candidate;
    Node * child;

    //determine candidate
    if(node->left == nullptr || node->right == nullptr) candidate = node;
    else {
        candidate = get_successor(node);
        node->key = candidate->key;
    }

    //determine child
    //here we covered case 1(0child) and case2(1child), because child will be nullptr automatically in case 1
    if(candidate->left!=nullptr) child = candidate->left;
    else child = candidate->right;
    
    //set child's new parent as candidate's parent
    if(child!=nullptr) child->parent = candidate->parent;

    //if we should delete root, then set the new root
    if(candidate->parent == nullptr) root = child;
    //set candidate's parent as child;
    else if(candidate->parent->left == candidate) candidate->parent->left = child;
    else candidate->parent->right = child;

    delete candidate; 
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
            if(find_node(k)!=nullptr) printf("yes\n");
            else printf("no\n");
        }
        else if(command[0] == 'd'){
            scanf("%d",&k);
            delete_node(find_node(k));
        }
        else print_tree();
    }
}
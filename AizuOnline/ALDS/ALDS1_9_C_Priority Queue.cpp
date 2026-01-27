#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 5e5;
typedef vector<int>::iterator v_it;
vector<int> A {-1};

int parent(int idx){ return idx/2;}
int left(int idx){ return 2*idx; }
int right(int idx){ return 2*idx+1;}

void insert(int key){
    A.push_back(key);
    int i = A.size()-1;
    while(i>1&&A[i]>A[parent(i)]){
        swap(A[parent(i)],A[i]);
        i = parent(i);
    }
}

void maxHeapify(int i){
    int l_idx = left(i);
    int r_idx = right(i);
    int largest_idx;
    if(r_idx<A.size() && A[r_idx]>A[i]) largest_idx = r_idx;
    else largest_idx = i;
    if(l_idx<A.size() && A[l_idx]>A[largest_idx]) largest_idx = l_idx;
    if(i!=largest_idx) {
        swap(A[i],A[largest_idx]);
        maxHeapify(largest_idx);
    }
}

int extractMax(){
    swap(A.back(),A[1]);
    int maxV = A.back(); A.pop_back();
    maxHeapify(1);
    return maxV;
}

int main(){
    char command[20];
    int k;
    for(scanf("%s",command); strcmp(command,"end"); scanf("%s",command)){
        if(command[0] == 'i') {
            cin>>k; 
            insert(k);
        }else{
            printf("%d\n",extractMax());
        }
    }
}


//solution on book
/*
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 2e6;
const int INF = 1<<30;
int A[MAXN+1],H=0;


int parent(int idx){ return idx/2;}
int left(int idx){ return 2*idx; }
int right(int idx){ return 2*idx+1;}

void increaseKey(int i,int key){
    if(key<A[i]) return;
    A[i] = key;
    for(; i>1 && A[i]>A[i/2]; i = parent(i)) swap(A[i],A[i/2]); 
}

void insert(int key){
    H++;
    A[H] = -INF;
    increaseKey(H,key);
}

void maxHeapify(int i){
    int l_idx = left(i);
    int r_idx = right(i);
    int largest_idx;
    if(r_idx<= H && A[r_idx]>A[i]) largest_idx = r_idx;
    else largest_idx = i;
    if(l_idx<= H && A[l_idx]>A[largest_idx]) largest_idx = l_idx;
    if(i!=largest_idx) {
        swap(A[i],A[largest_idx]);
        maxHeapify(largest_idx);
    }
}

int extractMax(){
    if(H<1) return -INF;
    int maxV = A[1];
    A[1] = A[H];
    H--;
    maxHeapify(1);
    return maxV;
}

int main(){
    string command;
    int k;
    for(cin>>command; command!="end"; cin>>command){
        if(command[0] == 'i') {
            cin>>k; 
            insert(k);
        }else{
            cout<<extractMax()<<endl;
        }
    }
}

*/
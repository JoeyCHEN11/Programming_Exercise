#include <iostream>
#include <algorithm> 
using namespace std;
const int MAXN = 5e5;
int A[MAXN+1] = {0};
int H;

int parent(int i){ return i/2; }
int left(int i){ return 2*i; }
int right(int i){ return 2*i+1;}

void maxHeapify(int i){
    int l_idx = left(i);
    int r_idx = right(i);
    int largest_idx;
    if(r_idx<=H && A[r_idx]>A[i]) largest_idx = r_idx;
    else largest_idx = i;
    if(l_idx<=H && A[l_idx]>A[largest_idx]) largest_idx = l_idx;
    if(i!=largest_idx) {
        swap(A[i],A[largest_idx]);
        maxHeapify(largest_idx);
    }
}

void buildMaxHeap(){
    for(int i = H/2; i >= 1; i-- ) maxHeapify(i);
}

int main(){

    cin>>H;

    for(int i = 1; i < H+1; i++){
        cin>>A[i];
    }
    buildMaxHeap();
    for(int i = 1; i < H+1; i++){
        cout<<" "<<A[i];
    }
    cout<<endl;
}
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5;
int A[MAXN] = {0};


int partition1(int p, int r){
    int x = A[r];
    int i = p;
    int j = r-1;
    do{
        while(A[i] < x) i++;
        while(A[j] >= x && i < j) j--;
        if(i<j) swap(A[i],A[j]);
    }while(i<j);
    swap(A[i],A[r]);
    return i;
}

int partition2(int p, int r){
    int x = A[r];
    //i group: all elements which <= x
    int i = p-1; 
    for(int j = p; j<r; j++){//check j group: all elements after i group, which > x
        if(A[j]<=x){
            i++;
            swap(A[i],A[j]);//swap it to the i group
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>A[i];
    }
    int q = partition2(0,n-1);
    for(int i = 0; i<n; i++){
        if(i != q) cout<<A[i];
        else cout<<"["<<A[i]<<"]";
        if(i!=n-1) cout<<" ";
        else cout<<endl;
    }
}
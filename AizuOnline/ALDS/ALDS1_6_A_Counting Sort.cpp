#include <iostream>
#include <algorithm>
using namespace std;
const int MAXSIZE = 2e6;
const int MAXVALUE = 1e4+1;
int A[MAXSIZE] = {0};
int Count[MAXVALUE] = {0};
int B[MAXSIZE] = {0};
int n;

void countingSort(){
    for(int i = 0; i<n; i++) {
        Count[A[i]] += 1;
    }
    for(int i = 1; i < MAXVALUE; i++){
        Count[i] += Count[i-1];//The total number of occurrences of numbers which <= A[i] in A (cumulative count) 
    }
    for(int j = n-1; j>=0; j--){//keep stable
        int idx = Count[A[j]]-1;
        B[idx] = A[j];
        Count[A[j]]--;
    }
}

int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>A[i];
    }
    countingSort();
    for(int i = 0; i<n; i++){
        cout<<B[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;
}
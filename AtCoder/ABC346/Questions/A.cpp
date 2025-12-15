#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<int> A;

    cin>>n;
    A.resize(n);
    for(auto & a : A) cin>>a;

    for(int i = 0; i < n - 1; i++){
        cout<< A[i] * A[i + 1]<<' ';
    }
    cout<<endl;
}
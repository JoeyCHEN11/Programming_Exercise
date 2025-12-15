#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    vector<int> A;
    while(q--){
        int query, x;
        cin>>query>>x;
        if(query == 1) A.push_back(x);
        else cout<<*(A.end() - x)<<endl;
    }
}
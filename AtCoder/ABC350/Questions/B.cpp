#include <bits/stdc++.h>

using namespace std;

int n;
int toothRemain(vector<int> & ops){
    int ans = n;
    vector<bool> check(n + 1, true);

    for(auto t : ops){
        if(check[t]) ans--;
        else ans++;
        check[t] = !check[t];
    }
    return ans;
}

int main(){
    int q;
    cin>>n>>q;
    vector<int> ops(q);
    for(auto & t : ops) cin>>t;

    cout<<toothRemain(ops)<<endl;
}
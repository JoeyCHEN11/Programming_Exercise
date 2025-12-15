#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, k;
vector<ll> A;

ll getSum(){
    ll ans = (1 + k) * k / 2;
    unordered_set<ll> Aset(A.begin(), A.end());
    for(auto a : Aset) if( a >= 1 && a <= k) ans -= a;
    return ans;
}

int main(){
    cin>>n>>k;
    A.resize(n);
    for(auto & a : A) cin>>a;

    cout<<getSum()<<endl;
}
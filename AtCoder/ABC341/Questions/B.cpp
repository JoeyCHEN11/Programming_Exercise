#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int n;
vector<ll> currency;
vector<pair<int, int>> ops;

ll maxCurAtN(){
    
    for(int i = 0; i < n - 1; i++){
        auto [s, t] = ops[i];

        ll d = currency[i] / s;
        
        currency[i] -= d * s;
        currency[i + 1] += d * t;

    }
    
    return currency.back();
}



int main(){
    cin>>n;
    currency.resize(n);
    ops.resize(n - 1);
    for(auto& cur : currency) cin>>cur;

    for(auto& [s, t] : ops) cin>>s>>t;

    cout<<maxCurAtN()<<endl;

}
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int n;
vector<ll> stops;

void init(){
    cin>>n;
    stops.resize(n);
    for(auto & s : stops) cin>>s;
}

ll minCurr(){
    ll minInit = LLONG_MAX;
    ll sum = 0;
    for(auto stop : stops){
        sum += stop;
        minInit = min(minInit, sum);
    }
    minInit = max(-minInit, (ll)0);

    return sum + minInit;
}

int main(){

    init();
    cout<<minCurr()<<endl;
}


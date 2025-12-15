#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;


vector<pair<ll, ll>> divide(ll L, ll R){
    vector<pair<ll, ll>> ans;

    bool error = false;
    while(L != R && !error){
        int i = 0;
        while(L % (ll)pow((ll)2, (ll)i + 1) == 0 && L + (ll)pow((ll)2, (ll)i + 1) <= R){
            //cout<<i<<endl;
            i++;
        }
        ans.emplace_back(L, L + (ll)pow(2, i));

        L += pow(2, i);
    }

    return ans;
}

int main(){
    ll L, R;
    cin>>L>>R;
    vector<pair<ll, ll>> ans = divide(L, R);

    cout<<ans.size();
    for(auto [l, r] : ans){
        cout<<l<<' '<<r<<'\n';
    }
}
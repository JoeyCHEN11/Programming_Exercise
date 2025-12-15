#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
string s;
vector<int> cost;

ll minCostToGood(){
    // pre[i][0]: cost to obtain prefix of s[0, i - 1], end with 0, with alternative 0 and 1 ...0101010
    // suf[i][0]: suffix of s[i, n - 1], start with 0
    vector<vector<ll>> pre(n + 1, vector<ll>(2, 0)), suf(n + 1, vector<ll>(2, 0));
    pre[0][0] = 0;
    pre[0][1] = 0;
    suf[n][0] = 0;
    suf[n][1] = 0;

    for(int i = 1; i <= n; i++){
        pre[i][0] = pre[i - 1][1];
        pre[i][1] = pre[i - 1][0];

        if(s[i - 1] == '0') pre[i][1] += cost[i - 1];
        if(s[i - 1] == '1') pre[i][0] += cost[i - 1];
    }

    for(int i = n - 1; i >= 0; i--){
        suf[i][0] = suf[i + 1][1];
        suf[i][1] = suf[i + 1][0];

        if(s[i] == '0') suf[i][1] += cost[i];
        if(s[i] == '1') suf[i][0] += cost[i];
    }

    ll ans = LONG_LONG_MAX;

    for(int i = 0; i < n; i++) ans = min({ans, pre[i][0] + suf[i][0], pre[i][1] + suf[i][1]});

    return ans;

}

int main(){
    cin>>n;
    cin>>s;
    cost.resize(n);
    for(auto & c : cost) cin>>c;

    cout<<minCostToGood()<<endl;
}
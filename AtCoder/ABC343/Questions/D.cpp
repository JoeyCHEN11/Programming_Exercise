#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int n, t;
//          Ai, Bi
vector<pair<int, int>> record;
vector<ull> scores;
unordered_map<ull, int> check;

vector<int> diifs(){
    vector<int> ans;
    for(auto [a, b] : record){
        // cout<<"check["<<scores[a]<<"]: "<<check[scores[a]]<<", size:"<<check.size()<<endl;

        check[scores[a]]--;
        if(check[scores[a]] == 0) check.erase(scores[a]);

        scores[a] += b;
        check[scores[a]]++;
        // cout<<"edit: check["<<scores[a]<<"]: "<<check[scores[a]]<<", size:"<<check.size()<<endl;
        ans.emplace_back(check.size());
    }
    
    return ans;
} 


int main(){
    cin>>n>>t;
    scores.resize(n, 0);
    check[0] = n;
    record.resize(t);

    for(auto & [a, b] : record) {
        cin>>a>>b;
        a--;
    }

    vector<int> ans = diifs();

    for(auto d : ans) cout<<d<<endl;
}


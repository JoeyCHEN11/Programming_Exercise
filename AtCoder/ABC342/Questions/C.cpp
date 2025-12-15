#include <bits/stdc++.h>

using namespace std;

int n, q;
string s;
unordered_map<char, char> replaces;
vector<pair<char, char>> ops;

string changeS(){
    for(char c = 'a'; c <= 'z'; c++) replaces[c] = c;

    for(auto [c, d] : ops){
        for(auto [origin, current] : replaces){
            if(current == c) replaces[origin] = d;
        }
    }
    
    string ans;
    for(int i = 0; i < n; i++){
        ans.push_back(replaces[s[i]]);
    }
    return ans;
}

int main(){
    cin>>n;
    cin>>s;
    cin>>q;
    ops.resize(q);
    for(auto & [c, d] : ops) cin>>c>>d;

    cout<<changeS()<<endl;

}


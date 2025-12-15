#include <bits/stdc++.h>

using namespace std;

string s, t;

vector<int> correctPos(){
    vector<int> ans;
    int m = s.size();
    int n = t.size();

    // vector<queue<int>> check(26);
    // for(int i = 0; i <n; i++) {
    //     char c = t[i];
    //     check[c - 'a'].emplace(i + 1);
    // }
    // for(char c : s){
    //     int pos = check[c - 'a'].front(); check[c - 'a'].pop();
    //     ans.push_back(pos);
    // }

    int j = 0;
    for(int i = 0; i < n; i++){
        if(s[j] == t[i]){
            ans.push_back(i + 1);
            j++;
        }
    }
    
    return ans;
}

int main(){
    cin>>s>>t;
    vector<int> ans = correctPos();

    for(int pos : ans) cout<<pos<<' ';
    cout<<'\n';
}
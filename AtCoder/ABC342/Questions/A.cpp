#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;

    vector<int> check(26, 0);
    for(char c : s) check[c - 'a']++;
    // for(auto che : check)cout<<che<<endl;

    int pos = 0;
    for(int i = 0; i < s.size(); i++){
        if(check[s[i] - 'a'] == 1) {
            pos = i + 1;
            break;
        }
    }
    cout<<pos<<endl;

}
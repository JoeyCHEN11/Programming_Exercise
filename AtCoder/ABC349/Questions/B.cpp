#include <bits/stdc++.h>

using namespace std;

bool isGood(string & s){
    //            char, #
    unordered_map<char, int> check;
    //           time, #
    unordered_map<int, int> appear;

    for(char c : s) check[c]++;
    
    for(auto [c, cnt] : check) appear[cnt]++;
    
    for(auto [cnt, let] : appear) if(let != 2) return false;

    return true;
}

int main(){
    string s;
    cin>>s;
    cout<<(isGood(s)? "Yes":"No")<<'\n';
}
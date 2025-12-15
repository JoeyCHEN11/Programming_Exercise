#include <bits/stdc++.h>

using namespace std;

bool isAirpotCode(string & s, string & t){
    int m = t.back() == 'X'? 2 : 3, n = s.size();
    
    int j = 0;
    for(int i = 0; i < n; i++){
        if(toupper(s[i]) == t[j]){
            j++;
        }

        if(j == m) return true;
    }
    return false;
}

int main(){
    string s, t;
    cin>>s>>t;
    cout<<(isAirpotCode(s, t)? "Yes" : "No")<<'\n';
}
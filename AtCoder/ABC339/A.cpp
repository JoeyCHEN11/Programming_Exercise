#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    reverse(s.begin(), s.end());

    string ans = s.substr(0, s.find('.'));
    reverse(ans.begin(), ans.end());

    cout<<ans<<endl;
}
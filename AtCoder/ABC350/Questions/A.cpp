#include <bits/stdc++.h>

using namespace std;

bool isPastABC(string & s){
    string pre = s.substr(0, 3);
    int num = stoi(s.substr(3,3));
    if(pre != "ABC" ||
        num == 316||
        num <= 0 ||
        num >= 350) return false;
    return true;
}

int main(){
    string s;
    cin>>s;
    cout<<(isPastABC(s)? "Yes" : "No")<<endl;
}
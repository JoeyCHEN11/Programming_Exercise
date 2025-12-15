#include <iostream>

using namespace std;

bool leftrightarrow(const string & s){
    if(s[0]!='<' || s.back() != '>') return false;

    int n = s.size();
    for(int i = 1; i < n - 1; i++) if(s[i] != '=') return false;

    return true;
}

int main(){
    string s;
    cin>>s;
    if(leftrightarrow(s)) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';    
}
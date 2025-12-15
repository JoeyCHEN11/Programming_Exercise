#include <bits/stdc++.h>

using namespace std;

string s;
string itom = "wbwbwwbwbwbw";

bool hasSubstr(int w, int b){
    while(s.size() < w + b) s += itom;
    s += s;
    int n = s.size();
    //  0: w, 1: b
    int check[2] {0};

    int j = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'w') check[0]++;
        if(s[i] == 'b') check[1]++;

        if(check[0] == w && check[1] == b) return true;
        
        while(check[0] > w || check[1] > b) {
            if(s[j] == 'w') check[0]--;
            if(s[j] == 'b') check[1]--;
            j++;
        }
    }

    return false;
}


int main(){
    int w, b;
    cin>>w>>b;
    cout<<(hasSubstr(w, b)? "Yes" : "No")<<endl;
}
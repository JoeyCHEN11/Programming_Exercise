#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

ull n;

bool isPalindromic(string&& s){
    string t = s;
    reverse(t.begin(),t.end());
    return t == s;
} 

ull findParlinCube(){
    ull ans = 0;
    ull x = 1;

    while(pow(x, 3) <= n){
        if(isPalindromic(to_string((ull)pow(x, 3)))) ans = pow(x, 3);
        x++;
    }
    return ans;

}

int main(){
    cin>>n;

    cout<<findParlinCube()<<endl;
}


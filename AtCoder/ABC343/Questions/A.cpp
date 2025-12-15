#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    int wrongAns = 0;
    while(wrongAns == a + b) wrongAns++;
    cout<<wrongAns<<endl;
}
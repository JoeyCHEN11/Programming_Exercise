#include <bits/stdc++.h>

using namespace std;

vector<int> buildings;

int n;

int leftmostHigher(){
    for(int i = 1; i < n; i++) if(buildings[i] > buildings[0]) return i + 1;
    return -1;
}

int main(){
    cin>>n;
    buildings.resize(n);
    for(auto & b : buildings) cin>>b;

    cout<<leftmostHigher()<<endl;
}
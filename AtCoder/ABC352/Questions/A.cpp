#include <bits/stdc++.h>

using namespace std;

bool stopAtZ(int x, int y, int z){
    if(x > y) swap(x, y);

    return x < z && z < y;
}

int main(){
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    cout<<(stopAtZ(x, y, z)? "Yes" : "No")<<endl;
}
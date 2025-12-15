#include <bits/stdc++.h>

using namespace std;

vector<int> line;
vector<int> pos;
int n, q;



int main(){
    cin>>n;
    line.resize(n);
    pos.resize(n + 1);

    for(auto & per : line) cin>>per;

    for(int i = 0; i < n; i++){
        pos[line[i]] = i;

    }

    cin>>q;
    int a, b;
    while(q--){
        cin>>a>>b;
        cout<<(pos[a] < pos[b]? a : b)<<endl;
    }

}


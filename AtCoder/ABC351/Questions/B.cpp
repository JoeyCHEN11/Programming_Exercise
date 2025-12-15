#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<char>> A;
vector<vector<char>> B;

pair<int, int> findDiff(){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            if(A[i][j] != B[i][j]) return {i, j};
        }
    }
    return {-1, -1};
}

int main(){
    cin>>n;
    A.resize(n, vector<char>(n));
    B.resize(n, vector<char>(n));
    for(auto& row : A){
        for(auto& a : row){
            cin>>a;
        }
    }
    for(auto& row : B){
        for(auto& b : row){
            cin>>b;
        }
    }
    auto [i, j] = findDiff();
    cout<<i + 1<<' '<<j + 1<<endl;
}
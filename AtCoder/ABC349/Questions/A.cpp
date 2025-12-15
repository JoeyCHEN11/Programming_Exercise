#include <bits/stdc++.h>

using namespace std;

vector<int> scores;
int n;

int finalScore(){
    return -accumulate(scores.begin(), scores.end(), 0);
}

int main(){
    cin>>n;
    scores.resize(n - 1, 0);
    for(int & s : scores) cin>>s;

    cout<<finalScore()<<'\n';
}
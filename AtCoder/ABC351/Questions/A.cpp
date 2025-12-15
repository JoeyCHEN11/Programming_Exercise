#include <bits/stdc++.h>

using namespace std;

int bottomNineth(vector<int> & A, vector<int>& B){
    int sumA = accumulate(A.begin(), A.end(), 0);
    int sumB = accumulate(B.begin(), B.end(), 0);

    return sumA - sumB + 1;
}

int main(){
    vector<int> A, B;
    int n = 9, score;
    for (int i = 0; i < 9; i++){
        cin>>score;
        A.emplace_back(score);
    }
    for (int i = 0; i < 8; i++){
        cin>>score;
        B.emplace_back(score);
    }
    cout<<bottomNineth(A, B);
}
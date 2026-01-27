#include <iostream>

using namespace std;

const int MAXN = 45;
int FIB_DP[MAXN] = {0};

// O(2^n)
int fibonacci_rec(int i){
    if(i == 0 || i == 1) return 1; 
    else return fibonacci_rec(i-1) + fibonacci_rec(i-2);
}

int fibonacci_memo_rec(int i){
    if(i == 0 || i == 1) return FIB_DP[i] = 1; 
    else if(FIB_DP[i] != 0) return FIB_DP[i];
    else return FIB_DP[i] = fibonacci_memo_rec(i-1) + fibonacci_memo_rec(i-2);
}

// O(n)
void build_fibonacci(){
    FIB_DP[0] = FIB_DP[1] = 1;
    for(int i = 2; i < MAXN; i++){
        FIB_DP[i] = FIB_DP[i-1] + FIB_DP[i-2];
    }
} 



int main(){
    int n;
    
    cin>>n;

    //brute force 
    //cout<<fibonacci_rec(n)<<endl;

    //memorization of recursion
    //cout<<fibonacci_memo_rec(n)<<endl;

    //iteration dp
    build_fibonacci();
    cout<<FIB_DP[n]<<endl;
}

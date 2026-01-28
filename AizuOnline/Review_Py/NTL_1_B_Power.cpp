#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



long long pow_mod_rec(long long x, long long n, int M){
    if(!n) return 1;
    long long res = pow_mod_rec(x * x % M, n / 2, M);
    if(n % 2) res = res * x % M;
    return res;
}

long long pow_mod(long long x, long long n, int M){
    long long res = 1;
    while(n > 0){
        if(n & 1) res = res * x % M;
        x = x * x % M;
        n >>= 1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int x, n;
    int M = 1e9 + 7;
    cin>>x>>n;
    cout<<pow_mod(x, n, M)<<endl;
    return 0;
}

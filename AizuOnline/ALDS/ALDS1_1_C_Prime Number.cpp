#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int x){
    if(x == 2) return true;
    
    if(x <= 1 || x % 2 == 0) return false;
    int sqrt_x = sqrt(x);
    //                      +2 because only check odd number
    for(int i = 3; i <= sqrt_x; i += 2){
        if(x%i == 0) return false;  
    } 
    return true;
}

int main(int argc, char const *argv[])
{
    int n, x, cnt = 0;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>x;
        cnt += is_prime(x);
    }
    cout<<cnt<<endl;
    return 0;
}

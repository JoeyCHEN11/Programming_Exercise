#include <iostream>
#include <cmath>

using namespace std;

int get_gcd(int x, int y){
    if(x < y) swap(x, y);

    int r;
    while(y > 0){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int get_gcd_rec(int x, int y){
    return y? get_gcd_rec(y, x % y) : x;
}

int main(int argc, char const *argv[])
{
    int x, y;
    cin>>x>>y;
    cout<<get_gcd(x, y)<<endl;
    return 0;
}

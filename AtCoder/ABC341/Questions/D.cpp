#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
ull n, m, k;

int main(){
    cin>>n>>m>>k;

    ull x = lcm(n, m);

    ull left = 1, right = 1e18;

    while(left < right){
        ull mid =  (right + left) / 2;
        ull cnt = mid / m + mid / n - 2 * (mid / x);
        if(cnt < k) left = mid + 1;
        else right = mid;
    }

    cout<<right<<endl;
}
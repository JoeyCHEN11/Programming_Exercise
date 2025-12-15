#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void prime_factorize(int n, vector<int> & ans){

    for(int f = 2; f * f <= n; f++){
        while(n % f == 0){
            ans.push_back(f);
            n /= f;
        }
    }
    if(n>1) ans.push_back(n);
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> ans;

    prime_factorize(n, ans);
    cout<<n<<":";
    for(int a : ans) cout<<" "<<a;
    cout<<endl;

    return 0;
}

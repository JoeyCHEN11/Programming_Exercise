#include <iostream>
#include <vector>

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

int get_lcm(int n, vector<int>& nums){
    if(n < 1) return -1;
    int lcm = 1;
    for(int i = 0; i < n; i++) lcm = lcm * nums[i] / get_gcd(lcm, nums[i]);  
    return lcm;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int & a : nums) cin>>a;
    cout<<get_lcm(n, nums)<<endl;
    return 0;
}

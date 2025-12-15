#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int n;
const static ull MOD = 998244353;
vector<ull> nums;

ull concatenate(ull a, ull b){
    return a * pow((ull)10, to_string(b).size()) + b;
}

ull getfBrute(){
    ull ans = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            ans += (concatenate(nums[i], nums[j])) % MOD;
        }
        
    }
    return ans % MOD;
}

ull getf(){
    ull ans = 0, m = 0, s = 0;
    for(int i = n - 1; i >= 0; i--){
        ull a = nums[i];
        ans = (ans + m * (a) + s) % MOD;
        m = (m + (ull)pow((ull)10, to_string(a).size())) % MOD;
        s = (s + a) % MOD;
    }
    return ans;
}

int main(){

    cin>>n;
    nums.resize(n);
    for (auto& a : nums) {
        cin>>a;
    }

    cout<<getf()<<endl;

}
#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
vector<int> nums;
int n;

bool isSquare(int a, int b){
    return (ull)sqrt(a * b) * (ull)sqrt(a * b) == (ull)a * b;
}
int main(){
    cin>>n;
    nums.resize(n);
    for(auto & num : nums) cin>>num;
    
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(isSquare(nums[i], nums[j])) cnt++;
        }
    }
    cout<<cnt<<endl;

}
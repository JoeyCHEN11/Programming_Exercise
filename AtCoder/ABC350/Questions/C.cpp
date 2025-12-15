#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;

vector<pair<int, int>> swapSort(){
    vector<pair<int, int>> ans;
    for(int i = 0; i <= n; i++){
        while(nums[i] != i){
            ans.emplace_back(i, nums[i]);   
            swap(nums[i], nums[nums[i]]);
        }
    }
    return ans;
}

int main(){
    cin>>n;
    nums.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) cin>>nums[i];

    vector<pair<int, int>> ans = swapSort();

    cout<<ans.size()<<endl;
    for(auto [i, j] : ans){
        cout<<i<<' '<<j<<'\n';
    }
}
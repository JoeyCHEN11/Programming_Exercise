#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
int n, k;

int minGis(){
    int ans = n;
    vector<int> pos(n + 1, 0);
    deque<int> maxs, mins;
    for(int i = 0; i < n; i++){
        pos[nums[i]] = i;
    }

    int j = 1;
    for(int i = 1; i <= n; i++){
        while(!maxs.empty() && maxs.back() < pos[i]) maxs.pop_back();
        maxs.push_back(pos[i]);
        while(!mins.empty() && mins.back() > pos[i]) mins.pop_back();
        mins.push_back(pos[i]);


        if(i - j + 1 == k) {
            ans = min(maxs.front() - mins.front(), ans);
            if(!maxs.empty() && pos[j] == maxs.front()) maxs.pop_front();
            if(!mins.empty() && pos[j] == mins.front()) mins.pop_front();
            j++;
        }
    }

    return ans;
}

int main(){
    cin>>n>>k;
    nums.resize(n);
    for(int & num : nums) cin>>num;
    cout<<minGis()<<'\n';
}


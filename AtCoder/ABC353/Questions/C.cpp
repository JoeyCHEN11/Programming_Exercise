#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int n;
const static int MOD = 1e8;
vector<ull> nums;

//反过来求：总sum（取出所有数对的总和：每个数会被取出n - 1 次，所以等于（n - 1) * 累计和）与答案的差，检查：每一项加和的mod后，是否超过了1e8？若是，则最终答案要减去一个1e8
//先排序，再使用双指针，如果left + right > 1e8， 则left右边的所有和right的和都会超过1e8 1次，所以累计次数+= (right - left)
//最后输出sum - 超过的次数 * 1e8即可。
ull getf(){
    sort(nums.begin(), nums.end());
    ull ans = (n - 1) * accumulate(nums.begin(), nums.end(), (ull)0);
    int right = n - 1, left = 0;
    ull offset = 0;
    while(right > left){
        if(nums[left] + nums[right] >= MOD){
            offset += right - left;
            right--;
        }else{
            left++;
        }
    }
    return ans - offset * MOD;
}

int main(){

    cin>>n;
    nums.resize(n);
    for (auto& a : nums) {
        cin>>a;
        // a = a % MOD;
    }

    cout<<getf()<<endl;

}
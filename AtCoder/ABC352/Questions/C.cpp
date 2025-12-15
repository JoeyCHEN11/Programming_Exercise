#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
struct Giant{
    ull shoulder, head;
};
vector<Giant> giants;
int n;
/**

 * @brief 贪心：处于top的巨人一定是max(g.head - g.shoulder)的那个，
 *        具体证明可以列出: g在top时的总高度(其他shoulder + g.head)
 *                   和: g不在(某g'在）top时的总高度(其他shouder + g'.head)
 *        然后证明前者恒大于后者即可。
 * 
 * @return ull 
 */
ull maxHeight(){

    ull sum = (ull)accumulate(giants.begin(), giants.end(), 0, [](ull acc, Giant g)-> ull{ return acc + g.shoulder; });
    // ull sum = 0;
    for(auto g : giants) sum+= g.shoulder;
    ull ans = sum;
    for(auto g : giants){
        ans = max(ans, sum + (g.head - g.shoulder));
    }
    return ans;
}

int main(){
    cin>>n;
    giants.resize(n);
    for(auto& g : giants) cin>>g.shoulder>>g.head;
    
    cout<<maxHeight()<<'\n';

}
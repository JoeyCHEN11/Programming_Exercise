#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

ull n;
queue<ull> que;
        // num, cnt
unordered_map<ull, ull> cache;

ull divide(ull x){
    if(cache.count(x)) return cache[x];
    else return cache[x] = x + divide((x + 1) / 2) + divide(x / 2);
}

int main(){
    cin>>n;
    que.emplace(n);
    cache[1] = cache[0] = 0;
    cout<<divide(n)<<endl;
}
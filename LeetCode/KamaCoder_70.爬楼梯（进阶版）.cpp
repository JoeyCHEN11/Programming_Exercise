/**
 * KamaCoder_70.爬楼梯（进阶版）
 * 
 * 题目描述
 *  假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
 *  每次你可以爬至多m (1 <= m < n)个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
 *  注意：给定 n 是一个正整数。
 *
 *  输入共一行，包含两个正整数，分别表示n, m
 * 
 *  输出一个整数，表示爬到楼顶的方法数。
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> dp1D(n + 1, 0);
    dp1D[0] = 1;
    for(int t = 0; t <= n; t++){
        for(int i = 1; i <= m; i++){
            if(i <= t) dp1D[t] += dp1D[t - i];
        }
    }
    cout<<dp1D[n]<<endl;
}
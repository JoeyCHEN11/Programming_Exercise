#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXM = 2000;
const int MAXN = 20;
int A[MAXN] = {0};
int DP_A[MAXN+1] = {0};

//记忆化递归
//dp[i][m] = 在子序列A[i,n) 中，任意几个数相加能否得到m
// domain i: [0, n) m:[1, MAXM]
// -1:未计算; 0:不能; 1:能
vector<vector<char>> dp(MAXN,vector<char>(MAXM+1,-1));
int n,q;

bool sum_dp[MAXN+1][MAXM+1] = {false};

//若要回答问题"[i,n)序列中是否有组合能得到m",则可以将其拆分成子问题：“[i+1,n)序列中有组合能得到m"或"[i+1,n)序列中有组合能得到m-A[i]",即“不选i或选i"
//解决该问题后，将答案记录在dp[i][m]中，作为其它问题的子问题的直接答案，省去重复递归
bool pick_check(int i,int m){
    //判断问题是否抵达终止态
    if(m == 0) return true;
    else if(i >= n || m < 0) return false;
    //检查记忆过的子问题
    else if(dp[i][m] != -1) return dp[i][m];
    //若未记忆，进入递归
    else return dp[i][m] = pick_check(i+1,m-A[i])||pick_check(i+1,m);
}

//递归生成全部dp，从开头向后递归
void build_sum_dp(){
    for(int j = 0; j <= MAXN; j++) sum_dp[j][0] = true;
    for(int i = 1; i <= n; i++){
        for(int m = 1; m <= MAXM; m++){
            int nopick_m = m - DP_A[i];
            sum_dp[i][m] = nopick_m >=0? sum_dp[i-1][m]||sum_dp[i-1][nopick_m] : sum_dp[i-1][m];
        }
    }
}

int main(){
    cin>>n;
    // for(int i = 0; i < MAXN; i++){
    //     for(int j = 0; j < MAXM+1; j++){
    //         dp[i][j] = -1;
    //     }
    // }
    for(int i = 0; i < n; i++){
        cin>>A[i];
        DP_A[i+1] = A[i];
    }
    build_sum_dp();
    cin>>q;
    for(int i = 0; i < q; i++){
        int m;
        cin>>m;

        if(sum_dp[n][m]){
        //if(pick_check(0,m)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        
    }

}
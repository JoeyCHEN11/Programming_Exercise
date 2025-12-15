#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int MAXN = 1000;
int n;
vector<vector<double>> dp;
vector<vector<double>> w;

// O(mn)
void optimalBST(vector<double>& p , vector<double>& q){
    dp.clear();
    w.clear();
    dp.resize(n + 2, vector<double>(n + 1, INT32_MAX));
    w.resize(n + 2, vector<double>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i + 1][i] = q[i];
        w[i + 1][i] = q[i];
    }
    
    for(int len = 1; len <= n; len++){
        for(int i = 1; i <= n - len + 1; i++){
            int j = i + len - 1;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for(int r = i; r <= j; r++){
                dp[i][j] = min(dp[i][j], dp[i][r - 1] + dp[r + 1][j] + w[i][j]);
            }
        }

    }
    
} 

int main(){
    cin>>n;
    //          k1...kn
    vector<double> p(n + 1);
    //          d0...dn
    vector<double> q(n + 1);

    for(int i = 1; i <= n; i++){
        cin>>p[i];
    }
    for (int i = 0; i <= n; i++) {
        cin>>q[i];
    }
    optimalBST(p, q);
    cout<<setprecision(5)<<fixed<<dp[1][n]<<endl;
}

#include <iostream>

using namespace std;

const int MAXN = 100;
const int INF = 1<<30;
int M_CHAIN_COST[MAXN+1][MAXN+1] = {0};
int ROW_COL[MAXN+1] = {0};
int n; 
 
// O(mn)
void build_M_CHAIN(){
    for(int length = 2; length <= n; length++){
        for(int i = 1; i <= n - length + 1; i++){
            int j = i + length - 1;
            M_CHAIN_COST[i][j] = INF;
            for(int k = i; k < j; k++){
                M_CHAIN_COST[i][j] = min(M_CHAIN_COST[i][j], M_CHAIN_COST[i][k] + M_CHAIN_COST[k+1][j] + ROW_COL[i-1] * ROW_COL[k] * ROW_COL[j]);
            }
        }
    }
} 

int main(){
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>ROW_COL[i-1];
        cin>>ROW_COL[i];
    }
    build_M_CHAIN();
    cout<<M_CHAIN_COST[1][n]<<endl;
  
}

#include <iostream>
#include <vector>

using namespace std;

static const int MAXN = 50000 + 1;
static const int MAXM = 20 + 1;
static const int INF = 50000 + 1;

int T[MAXM][MAXN] = {0};
int T_1D[MAXN] = {0};
int get_number_of_coin(int n, int m, const vector<int> & coins){

    //1-d array
    for(int i = 1; i <= n; i++) T_1D[i] = INF;
    for(int i = 0; i <= m; i++){
        for(int j = coins[i]; j <= n; j++){
            T_1D[j] = min(T_1D[j], T_1D[j - coins[i]] + 1);
        }
    }
    return T_1D[n];

    
    // for(int i = 1; i <= n; i++) T[0][i] = INF;
    
    // //[1~i] coins
    // for(int i = 1; i <= m; i++){
    //     for(int j = 0; j <= n ; j++){
    //         if(j < coins[i]) T[i][j] = T[i - 1][j];
    //         else T[i][j] = min(T[i][j - coins[i]] + 1, T[i - 1][j]);
    //     } 
    // }

    // return T[m][n];

    
}



int main(int argc, char const *argv[])
{
    
    int n, m, c;
    vector<int> coins;
    cin>>n>>m;
    coins.resize(21);
    for(int i = 1; i <= m; i++){
        cin>>coins[i];
    }
    cout<<get_number_of_coin(n, m, coins)<<endl;

    return 0;
}

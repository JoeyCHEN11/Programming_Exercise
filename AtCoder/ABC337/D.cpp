#include <bits/stdc++.h>

using namespace std;

int main(){
    int H, W, K;
    cin>>H>>W>>K;
    vector<string> grid(H);
    for (string & s : grid) cin>>s;
    int INF = INT32_MAX;

    auto dpVertic = vector(H + 1, vector(W + 1, vector(K + 1, INF)));
    auto dpHori = vector(H + 1, vector(W + 1, vector(K + 1, INF)));

    int ansVertic = INF;
    int ansHori = INF;
    for (int i = 0; i <= H; i++){
        for(int j = 0; j <= W; j++){
            dpHori[i][j][0] = 0;
            dpVertic[i][j][0] = 0;
        }
    }

    for (int k = 1; k <= K; k++){
        for (int i = 1; i <= H; i++){
            for(int j = 1; j <= W; j++){
                if (grid[i - 1][j - 1] == 'x'){
                    dpVertic[i][j][k] = min(INF, dpVertic[i - 1][j][k]);
                    dpHori[i][j][k] = min(INF, dpHori[i][j - 1][k]);
                }
                else if (grid[i - 1][j - 1] == '.'){
                    if(dpVertic[i - 1][j][k - 1] != INF){
                        dpVertic[i][j][k] = min(dpVertic[i - 1][j][k - 1] + 1, dpVertic[i - 1][j][k]);
                    }else{
                        dpVertic[i][j][k] = dpVertic[i - 1][j][k];
                    }

                    if(dpHori[i][j - 1][k - 1] != INF){
                        dpHori[i][j][k] = min(dpHori[i][j - 1][k - 1] + 1, dpHori[i][j - 1][k]);
                    }else{
                        dpHori[i][j][k] = dpHori[i][j - 1][k];
                    }
                }
                else{
                    dpVertic[i][j][k] = min(dpVertic[i - 1][j][k - 1], dpVertic[i - 1][j][k]);
                    dpHori[i][j][k] = min(dpHori[i][j - 1][k - 1], dpHori[i][j - 1][k]);
                }
            }
        }
    }

    for (int j = 1; j <= W; j++){
        ansVertic = min(ansVertic, dpVertic[H][j][K]);
    } 
    for (int i = 1; i <= H; i++){ 
        ansHori = min(ansHori, dpHori[i][W][K]);
    }
    int ans = min(ansHori, ansVertic);
    if (ans != INF){
        cout<<ans;
    }else{
        cout<<-1;
    }

}
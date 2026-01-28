#include <iostream>

using namespace std;

const int MAXN = 1000;
int X_Y_LCS[MAXN+1][MAXN+1] = {0};
int m, n;


// O(mn)
void build_LCS(string x, string y){
    x = ' ' + x;
    y = ' ' + y;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
        if(x[i] == y[j]) X_Y_LCS[i][j] = X_Y_LCS[i-1][j-1]+1;
        else X_Y_LCS[i][j] = max(X_Y_LCS[i-1][j],X_Y_LCS[i][j-1]); 
        }
    }
} 

int main(){
    int q;
    string x, y;
    cin>>q;

    for(int i = 0; i < q; i++){
        cin>>x>>y;
        m = x.size();
        n = y.size();
        build_LCS(x,y);
        cout<<X_Y_LCS[m][n]<<endl;
    }

}

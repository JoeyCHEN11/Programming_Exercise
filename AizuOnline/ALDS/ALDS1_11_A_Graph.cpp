#include <iostream>

using namespace std;

const int MAXN = 100;
int G[MAXN+1][MAXN+1] = {0};

int main(){
    int n,u,k,v;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>u>>k;
        for(int j = 0; j < k; j++){
            cin>>v;
            G[u][v] = 1;
        }
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j++){
            cout<<G[i][j];
            if(j!=n) cout<<" ";
        }
        cout<<endl;
    }
}
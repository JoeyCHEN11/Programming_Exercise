#include <iostream>

using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    int A[n][m] = {0};
    int b[m] = {0};
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>A[i][j];
        }
    }
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }

    for(int i = 0; i<n; i++){
        int result = 0;
        for(int j = 0; j<m; j++){
            result += A[i][j]*b[j];
        }
        cout<<result<<endl;
    }
}
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAXSIZE = 100+5;
int A[MAXSIZE][MAXSIZE] = {0};//n*m;
int B[MAXSIZE][MAXSIZE] = {0};//m*l;
long long C[MAXSIZE][MAXSIZE] = {0};//n*l
int main(int argc, char const *argv[])
{
    int n,m,l;
    cin>>n>>m>>l;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<l; j++){
            cin>>B[i][j];
            // 思路2：linear combination :B的第i行中，每一个(j)元素和A的第i列向量相乘
            // 即成为C的第j列的线性组合的一部分
            // for(int k = 0; k<n; k++)
            //     C[k][j] +=B[i][j]*A[k][i];
            // }
        }
        
    }


    for(int i = 0; i<n; i++){
        for(int j = 0; j<l;j++){
            for(int k = 0; k<m; k++){
                //思路1:常规算法
                C[i][j] += A[i][k]*B[k][j];
            }
            cout<<C[i][j];
            if(j!=l-1) cout<<" ";
        }
        cout<<endl;
    }

}

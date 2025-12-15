#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int table[105][105] = {0};
int main(int argc, char const *argv[])
{
    int r,c;
    cin>>r>>c;

    for(int i = 0; i<r+1; i++){
        for(int j = 0; j<c; j++){
            if(i!=r){
                cin>>table[i][j];
                table[i][c] += table[i][j];
                table[r][j] += table[i][j];
                table[r][c] += table[i][j];
            }
            cout<<table[i][j]<<" ";
        }
        cout<<table[i][c]<<endl;
    }
    // for(int i = 0; i<r+1; i++){
    //     for(int j = 0; j<c+1; j++){
    //         cout<<table[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

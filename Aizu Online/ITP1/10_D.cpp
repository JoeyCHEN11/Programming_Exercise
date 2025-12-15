#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1);
int main(int argc, char const *argv[]){
    int diff[105] = {0};
    int n,y;
    double D1,D2,D3;
    int DINF = -1;
    cin>>n;
    for(int i = 0; i<n; i++) cin>>diff[i];
    for(int i = 0; i<n; i++) {
        cin>>y;
        diff[i] = abs(diff[i] - y);
    }
    for(int i = 0; i<n; i++){
        D1 += diff[i];
        D2 += pow(diff[i],2);
        D3 += pow(diff[i],3);
        DINF = max(diff[i],DINF);
    }
    D2 = sqrt(D2);
    D3 = pow(D3,(double)1/3);

    cout<<fixed<<setprecision(10)<<D1<<endl<<D2<<endl<<D3<<endl<<(double)DINF;
}

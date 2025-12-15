#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1);
int main(int argc, char const *argv[]){
    int S[1000] = {0};
    int n,sum = 0;
    double  m = 0, variance = 0;
    for(cin>>n; n!=0; cin>>n){
        sum = 0;
        variance = 0;
        for(int i = 0; i<n; i++){
            cin>>S[i];
            sum += S[i];
        }
        m = (double)sum/n;
        //cout<<m<<endl;
        for(int i = 0; i<n; i++){
            variance += pow(S[i]-m,2); 
        }
        variance /= n;
        cout<<fixed<<setprecision(5)<<sqrt(variance)<<endl;
    }

}

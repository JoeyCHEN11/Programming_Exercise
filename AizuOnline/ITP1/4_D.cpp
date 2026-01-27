#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int INF = 1000000+1;

int main(int argc, char const *argv[])
{
    int n,a;
    cin>>n;
    int max = -INF;
    int min = INF;
    long long sum = 0;
    do{
        cin>>a;
        if(a<min) min = a;
        if(a>max) max = a;
        sum += a;
        n--;
    }while(n>0);
    cout<<min<<" "<<max<<" "<<sum<<endl;
    return 0;
}

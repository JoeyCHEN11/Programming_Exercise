#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//算π技巧
const double PI = acos(-1);
int main(int argc, char const *argv[])
{
    double r;
    cin>>r;
    cout<<fixed<<setprecision(5)<<M_PI*r*r<<" "<<2*PI*r<<endl;
    return 0;
}

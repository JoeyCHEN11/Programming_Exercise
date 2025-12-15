#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1);
int main(int argc, char const *argv[])
{
    int a,b,C;
    double Crad;
    double S,L,h;
    cin>>a>>b>>C;
    Crad = (double)C/180*PI;
    double c = sqrt(a*a+b*b-2*a*b*cos(Crad));
 
    h = b*sin(Crad);
    S = a*h/2;
    L = a + b + c;
    cout<<fixed<<setprecision(5)<<S<<endl<<L<<endl<<h<<endl;
}

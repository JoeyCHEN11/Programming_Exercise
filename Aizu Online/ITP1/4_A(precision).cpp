#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int a,b,d,r;
    double f;
    cin>>a>>b;
    d = a/b;
    r = a%b;
    f = (double)a/b;
    cout<<d<<" "<<r<<" ";
    //fix定点对齐，setprecision保留5位小数
    cout<<fixed<<setprecision(5)<<f<<endl;
    return 0;
}

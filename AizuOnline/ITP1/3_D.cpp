#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int a,b,c;
    cin>>a>>b>>c;
    int count = 0;
    for(int div=a; div<=b; div++)
        if(!(c%div)) count++;
    cout<<count<<endl;
    return 0;
}

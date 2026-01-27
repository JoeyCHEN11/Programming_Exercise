#include <iostream>
#include <cmath>

using namespace std;


int main(int argc, char const *argv[])
{
    int a,b;
    char op;
    for(cin>>a>>op>>b; op!='?';cin>>a>>op>>b){
        switch (op)
        {
        case '+':
            cout<<a+b<<endl;
            break;
        case '-':
            cout<<a-b<<endl;
            break;
        case '*':
            cout<<a*b<<endl;
            break;
        case '/':
            cout<<a/b<<endl;
            break;
        default:
            break;
        }
    }
}

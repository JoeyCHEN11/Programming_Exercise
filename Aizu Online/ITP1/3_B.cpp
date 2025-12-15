#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x;
    cin>>x;
    for(int i=0;x!=0;i++){
        cout<<"Case "<<i+1<<": "<<x<<endl;
        cin>>x;
    }
    return 0;
}

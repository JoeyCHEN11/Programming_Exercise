#include <iostream>
#include <cmath>

using namespace std;


int main(int argc, char const *argv[])
{
    int a,b;
    for(cin>>a>>b; a!=0 || b !=0; cin>>a>>b){
        if(a>b)swap(a,b);
        cout<<a<<" "<<b<<endl;
    }
        
}   

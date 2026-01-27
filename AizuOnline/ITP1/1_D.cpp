#include <iostream>
#include <string>
using namespace std;
int main(){
    int h,m,s;
    cin>>s;
    m = s/60;
    h = m/60;
    m %= 60;
    s %= 60;
    cout<<h<<":"<<m<<":"<<s<<endl;
}
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string num;
    for(cin>>num; num[0] != '0'; cin>>num){
        int sum = 0;
        for(int i = 0; i<num.length(); i++){
            sum += stoi(num.substr(i,1));
        }
        cout<<sum<<endl;
    }
}

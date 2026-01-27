#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string W,T;
    int counter = 0;
    cin>>W;
    for(cin>>T;T!="END_OF_TEXT";cin>>T){
        //transform(T.begin(),T.end(),T.begin(), ::tolower);
        for(int i = 0; i<T.size(); i++) T[i] = tolower(T[i]);
        if(W==T) counter++;
    }
    cout<<counter<<endl;
    
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int q,a,b;
    string str,command,p;
    cin>>str>>q;

    for(int i = 0; i<q; i++){
        cin>>command;
        if(command == "print"){
            cin>>a>>b;
            cout<<str.substr(a,b-a+1)<<endl;
        }
        else if(command == "reverse"){
            cin>>a>>b;
            string::iterator ai = str.begin();
            string::iterator bi = str.begin();
            for(int i = 0; i<a; i++) ai++;
            for(int i = 0; i<=b; i++) bi++;
            reverse(ai,bi);
        }
        else if(command == "replace"){
            cin>>a>>b>>p;
            str.replace(a,b-a+1,p);
        }
    }
    
}

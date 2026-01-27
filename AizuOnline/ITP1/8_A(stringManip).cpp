#include <iostream>
#include <string>
#include <cctype>//isupper(), tolower(), toupper()
using namespace std;

int main(int argc, char const *argv[])
{
    // 1:
    // char c = 90;
    // while(cin.get(c)){
    //     if(c>=65&&c<=90) c += 32;
    //     else if(c>=97&&c<=122) c -= 32;
    //     cout<<c;
    // }
    // cout<<endl;

    //2:
    string s;
    getline(cin,s);
    for(int i=0; i<s.length(); i++){
        if(isupper(s[i])) s[i] = tolower(s[i]);
        else if (islower(s[i])) s[i] = toupper(s[i]);
    }
    cout<<s<<endl;
}

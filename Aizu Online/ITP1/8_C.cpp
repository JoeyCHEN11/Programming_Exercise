#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int alphabetTable[26] = {0};
    char c;
    while(cin>>c){
        if(isalpha(c)){
            c = tolower(c);
            alphabetTable[c-97] += 1;
        }
    }
    for(int i; i<26; i++ ){
        cout<<(char)(i+97)<<" : "<<alphabetTable[i]<<endl;
    }

}

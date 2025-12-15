#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, taroP = 0, hanakoP = 0;
    string taroCard, hanakoCard;
    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>taroCard>>hanakoCard;
        if(taroCard>hanakoCard) taroP+=3;
        else if(taroCard<hanakoCard) hanakoP+=3;
        else {
            taroP++;
            hanakoP++;
        }
    }
    cout<<taroP<<" "<<hanakoP<<endl;
    
}

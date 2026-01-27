#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string cards;
    int m,h,sumH = 0;

    for(cin>>cards; cards!="-"; cin>>cards){
        sumH=0;
        cin>>m;
        for(int i = 0; i<m; i++){
            cin>>h;
            sumH+=h;
        }

        sumH %= cards.size();
        //cout<<sumH;
        cards += cards.substr(0,sumH);
        cout<<cards.substr(sumH,cards.size())<<endl;
        
        // string partOfCards = cards.substr(0,sumH);
        // string shuffcards = cards.substr(sumH,cards.size()-sumH) + partOfCards;
        // cout<<shuffcards<<endl;
    }

    
}

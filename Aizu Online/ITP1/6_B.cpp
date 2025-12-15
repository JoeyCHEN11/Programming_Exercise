#include <iostream>

using namespace std;

const int RANKNUM = 13;
const int SUITNUM = 4;
typedef struct _card{
    char suit;
    int rank;
}card;

int suitTOIndex(char suit){
    switch (suit)
    {
        case 'S':
            return 0;
        case 'H':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
    }
    return -1;
}

char indexToSuit(int index){
    switch (index)
    {
        case 0:
            return 'S';
        case 1:
            return 'H';
        case 2:
            return 'C';
        case 3:
            return 'D';
    }
    return 'N';
}



int main(){
    int n;
    int cards[SUITNUM][RANKNUM] = {0};
    
    cin>>n;
    for(int i = 0; i<n; i++){
        card newCard;
        cin>>newCard.suit>>newCard.rank;
        cards[suitTOIndex(newCard.suit)][newCard.rank-1] = 1;
    }

    for(int i = 0; i<SUITNUM; i++){
        for(int j = 0; j<RANKNUM; j++){
            if(!cards[i][j]){
                cout<<indexToSuit(i)<<" "<<j+1<<endl;
            }
        }
    }

    
}
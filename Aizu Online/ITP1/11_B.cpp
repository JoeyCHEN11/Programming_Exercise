#include <iostream>

using namespace std;

// typedef struct _dice{
//     int up;
//     int front;
//     int right;
//     int left;
//     int back;
//     int down;
// }dice;

int dice[6];
int diceRights[6][6] = {-1};

int findIndex(int x){
    for(int i =0; i<6; i++){
        if(x==dice[i]) return i;
    }
    return -1;
}

int main(){
    diceRights[3][1] = diceRights[1][2] = diceRights[2][4] = diceRights[4][3] = 0;
    diceRights[0][3] = diceRights[3][5] = diceRights[5][2] = diceRights[2][0] = 1;
    diceRights[0][1] = diceRights[1][5] = diceRights[5][4] = diceRights[4][0] = 2;
    diceRights[0][4] = diceRights[4][5] = diceRights[5][1] = diceRights[1][0] = 3;
    diceRights[0][2] = diceRights[2][5] = diceRights[5][3] = diceRights[3][0] = 4;
    diceRights[3][4] = diceRights[4][2] = diceRights[2][1] = diceRights[1][3] = 5;
    int q,top,topIndex,front,frontIndex;

    for(int i = 0; i<6; i++){
        cin>>dice[i];
    }
    cin>>q;

    for(int i = 0; i<q; i++){
        cin>>top>>front;
        topIndex = findIndex(top);//5
        frontIndex = findIndex(front);//0
        cout<<dice[diceRights[topIndex][frontIndex]]<<endl;
    }

    //cout<<dice[0]<<endl;
    return 0;
}
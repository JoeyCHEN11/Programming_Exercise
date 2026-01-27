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

void roll(char direction){
    if(direction == 'E'){
        int temp = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[2];
        dice[2] = dice[0];
        dice[0] = temp;
    }
    else if(direction == 'W'){
        int temp = dice[3];
        dice[3] = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[5];
        dice[5] = temp;
    }
    else if(direction == 'S'){
        int temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[5];
        dice[5] = dice[1];
        dice[1] = temp;
    }
    else if(direction == 'N'){
        int temp = dice[0];
        dice[0] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[4];
        dice[4] = temp;
    }
}


int main(){
    for(int i = 0; i<6; i++){
        cin>>dice[i];
    }
    for(char c; cin>>c; ) roll(c);
    cout<<dice[0]<<endl;
    return 0;
}
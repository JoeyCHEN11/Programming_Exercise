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


/*
    A dice template
    the dice is constructed by the following net:
        0
    3   1   2   4
        5
    default state: top: 0, front: 1, right: 2, left: 3, back: 4, bottom: 5
*/
class Dice{
private:
    int numbers[6];//face 0-5 
    int top_front_to_right[6][6] ; //for any state, given index of top-front, get the index of the right face;

public:
    int numbersTable[6][6][6]; //get nubers[] with given index of top-front-right, unavailabe state with all -1;
    void setNumber(int pos,int num){
        this->numbers[pos] = num;
    }
    void setNumbersTable(){
        for(int top_index = 0; top_index < 6; top_index++){
            for(int front_index = 0; front_index < 6; front_index++){
                if(top_index==front_index||top_index+front_index==5) continue;//when i=j or they are not adjacent, no available array
                int right_index = top_front_to_right[top_index][front_index];
                int left_index = 5 - right_index;
                int back_index = 5 - front_index;
                int bottom_index = 5 - top_index;
                numbersTable[top_index][front_index][0] = numbers[top_index];
                numbersTable[top_index][front_index][1] = numbers[front_index]; 
                numbersTable[top_index][front_index][2] = numbers[right_index];
                numbersTable[top_index][front_index][3] = numbers[left_index];
                numbersTable[top_index][front_index][4] = numbers[back_index];
                numbersTable[top_index][front_index][5] = numbers[bottom_index];
                // cout<<numbersTable[top_index][front_index][0]<<" ";
                // cout<<numbersTable[top_index][front_index][1]<<" ";
                // cout<<numbersTable[top_index][front_index][2]<<" ";
                // cout<<numbersTable[top_index][front_index][3]<<" ";
                // cout<<numbersTable[top_index][front_index][4]<<" ";
                // cout<<numbersTable[top_index][front_index][5]<<" ";
                // cout<<endl;
                //cout<<front_index<<" "<<right_index<<" "<<left_index<<" "<<back_index<<" "<<bottom_index<<endl;
            }
        }
        //cout<<"done";
    }

    bool equals(Dice & dice){
        bool flag;
        for(int i1 = 0; i1 < 6; i1++){
            for(int j1 = 0; j1 < 6; j1++){
                if(i1==j1||i1+j1==5) continue;
                for(int i2 = 0; i2<6; i2++){
                    for(int j2 = 0; j2<6; j2++){
                        if(i2==j2||i2+j2==5) continue;
                        flag = true;
                        //cout<<"compare: "<<endl;
                        for(int k = 0; k < 6; k++){
                            if(this->numbersTable[i1][j1][k] != dice.numbersTable[i2][j2][k]) {
                                flag = false;
                                break;
                            }
                            //cout<<this->numbersTable[i1][j1][k]<<" "<<dice.numbersTable[i2][j2][k]<<en dl;
                        }
                        //cout<<endl;
                        if(flag) return true;
                    }
                }
                
            }
        }
        return false;
    }

    Dice(){
        top_front_to_right[3][1] = top_front_to_right[1][2] = top_front_to_right[2][4] = top_front_to_right[4][3] = 0;
        top_front_to_right[0][3] = top_front_to_right[3][5] = top_front_to_right[5][2] = top_front_to_right[2][0] = 1;
        top_front_to_right[0][1] = top_front_to_right[1][5] = top_front_to_right[5][4] = top_front_to_right[4][0] = 2;
        top_front_to_right[0][4] = top_front_to_right[4][5] = top_front_to_right[5][1] = top_front_to_right[1][0] = 3;
        top_front_to_right[0][2] = top_front_to_right[2][5] = top_front_to_right[5][3] = top_front_to_right[3][0] = 4;
        top_front_to_right[3][4] = top_front_to_right[4][2] = top_front_to_right[2][1] = top_front_to_right[1][3] = 5;
        for(int i = 0; i < 6; i++){
            numbers[i] = -1;
            for(int j = 0; j < 6; j++){
                for(int k = 0; k < 6; k++){
                    numbersTable[i][j][k] = -1;
                }
            }
        }
    }
};



int main(){
    Dice dice1, dice2;
    int num;

    for(int i = 0; i<6; i++){
        cin>>num;
        dice1.setNumber(i,num);
    }
    for(int i = 0; i<6; i++){
        cin>>num;
        dice2.setNumber(i,num);
    }
    dice1.setNumbersTable();
    dice2.setNumbersTable();
    if(dice1.equals(dice2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    //cout<<dice[0]<<endl;
    return 0;
}
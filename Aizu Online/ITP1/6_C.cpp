#include <iostream>

using namespace std;

const int BUILDNUM = 4;
const int FLOORNUM = 3;
const int ROOMNUM = 10;


void printConditions(int rooms[BUILDNUM][FLOORNUM][ROOMNUM]){
    for(int b = 0; b<BUILDNUM; b++){
        for(int f = 0; f<FLOORNUM; f++){
            for(int r = 0; r<ROOMNUM; r++){
                cout<<" "<<rooms[b][f][r];
            }
            cout<<endl;
        }

        if(b!=BUILDNUM-1) cout<<"####################"<<endl;
    }
}

int main(){
    int n,b,f,r,v;
    int rooms[BUILDNUM][FLOORNUM][ROOMNUM] = {0};

    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>b>>f>>r>>v;
        rooms[b-1][f-1][r-1] += v;
    }
    printConditions(rooms);

}
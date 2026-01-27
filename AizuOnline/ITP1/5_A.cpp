#include <iostream>

using namespace std;

int main(){
    int H,W;
    for(cin>>H>>W; H!=0&&W!=0; cin>>H>>W){
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cout<<"#";
            }
            cout<<endl;
        }
        cout<<endl;
    }

}
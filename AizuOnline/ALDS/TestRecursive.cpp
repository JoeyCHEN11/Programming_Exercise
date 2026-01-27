#include <iostream>
using namespace std;
const int n=5;
int S[5]={0};
void rec(int i){
    if(i==n){
        for(int j=0;j<5;j++){
            cout<<S[j]<<" ";
        }
        cout<<endl;
        return;
    }
    
    S[i]=0;
    rec(i+1);
    S[i]=1;
    rec(i+1);
    
}
int main(){
    rec(0);
    for(int j=0;j<5;j++){
        cout<<S[j]<<" ";
    }
}
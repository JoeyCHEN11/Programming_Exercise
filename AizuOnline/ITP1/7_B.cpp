#include <iostream>

using namespace std;

int counter = 0;
void countComb(int x, int n, int addendNum){
    if(x<0) return;
    if(addendNum==0) {
        if(x==0){
            counter++;
            return;
        }
        else return;
    }
    else {
        for(int i = n; i>=1; i--){
            countComb(x-i,i-1,addendNum-1);
        }
    }
}

int main(){
    int n,x;
    for(cin>>n>>x;n!=0||x!=0;cin>>n>>x){
        counter = 0;
        for(int i = n>=x? x-3:n; !(i+(i-1)+(i-2)<x); i--){
            // for(int j = i-1>=x-i? x-i-1:i-1; i+j+j-1>=x; j--){
            //     // for(int k = j-1; k>=1; k--){
            //     //     if(i+j+k == x) {
            //     //         counter++;
            //     //         break;
            //     //     }
            //     // }
            //     counter++;
            // }
            int addend2 = i-1>=x-i? x-i-1:i-1;
            counter += addend2-((x+1-i)/2+(x+1-i)%2)+1;
        }
        //countComb(x,n, 3);
        cout<<counter<<endl;
    }
}
#include <iostream>

using namespace std;

void call(int n){
    for(int i = 1; i<=n; i++){
        if(i%3 == 0){
            cout<<" "<<i;
        }
        else{
            for(int x = i; x ; x /= 10){
                if(x%10 == 3){
                    cout<<" "<<i;
                    break;
                }
            }
        }
    }
}


int main(){
    int n=1,x=n;
    cin>>n;
    call(n);
    
}
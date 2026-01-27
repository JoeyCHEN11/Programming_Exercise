#include <iostream>

using namespace std;

int counter = 0;
int main(){
    int n,x;
    for(cin>>n>>x;n!=0||x!=0;cin>>n>>x){
        counter = 0;
        for(int i = n>=x? x-3:n; !(3*i-3<x); i--){
            for(int j = i-1; j>=2 ; j--){
                if(i+2*j-1<x) break;
                for(int k = j-1; k>=1; k--){
                    if(i+j+k == x) {
                        counter++;
                        break;
                    }
                }
            }
        }
        //countComb(x,n, 3);
        cout<<counter<<endl;
    }
}
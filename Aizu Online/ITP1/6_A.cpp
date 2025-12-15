#include <iostream>

using namespace std;


int main(){
    int n;
    int A[1000] = {0};
    
    cin>>n;

    for(int i = 0; i<n ; i++){
        cin>>A[i];
    }

    for(int i = n-1; i > 0; i--){
        cout<<A[i]<<" ";
    }
    cout<<A[0]<<endl;
}
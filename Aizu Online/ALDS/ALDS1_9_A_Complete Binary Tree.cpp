#include <iostream>

using namespace std;
const int MAXN = 250;
int A[MAXN+1] = {0};

int parent(int i){ return i/2; }
int left(int i){ return 2*i; }
int right(int i){ return 2*i+1;}

int main(){

    int h;
    cin>>h;

    for(int i = 1; i < h+1; i++){
        cin>>A[i];
    }

    for(int i = 1; i<h+1; i++){
        cout<<"node "<<i<<": key = "<<A[i]<<", ";
        if(parent(i)>=1) cout<<"parent key = "<<A[parent(i)]<<", ";
        if(left(i)<=h) {
            cout<<"left key = "<<A[left(i)]<<", ";
            if(right(i)<=h) cout<<"right key = "<<A[right(i)]<<", ";
        }
        cout<<endl;
    }
}
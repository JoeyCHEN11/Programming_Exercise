#include <iostream>
#include <vector>

using namespace std;

vector<int> A;

void push_back(int x){
    A.push_back(x);
}

int access(int p){
    return A[p];
}

int pop_back(){
    int x = A.back(); A.pop_back();
    return x;
}

int main(){
    int q,query,x;
    cin>>q;
    for(int i = 0; i<q; i++){
        cin>>query;
        switch (query)
        {
        case 0:
            cin>>x;
            push_back(x);
            break;
        case 1:
            cin>>x;
            cout<<access(x)<<endl;
            break;
        case 2:
            pop_back();
            break;
        default:
            break;
        }
    }
}
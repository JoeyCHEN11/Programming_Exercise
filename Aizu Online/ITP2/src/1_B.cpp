#include <iostream>
#include <deque>

using namespace std;

deque<int> A;


int main(){
    int q,query,d,p,x;
    cin>>q;
    for(int i = 0; i<q; i++){
        cin>>query;
        switch (query)
        {
        case 0:
            cin>>d>>x;
            if(d==0) A.push_front(x);
            else A.push_back(x);
            break;
        case 1:
            cin>>p;
            cout<<A[p]<<endl;
            break;
        case 2:
            cin>>d;
            if(d==0) A.pop_front();
            else A.pop_back();
            break;
        default:
            break;
        }
    }
}
#include <iostream>
#include <list>

using namespace std;

list<int> A;


int main(){
    int q,query,d,p,x;
    auto cur = A.begin();
    cin>>q;
    for(int i = 0; i<q; i++){
        cin>>query;
        switch (query)
        {
        case 0:
            cin>>x;
            cur = A.insert(cur,x);
            break;
        case 1:
            cin>>d;
            advance(cur,d);
            break;
        case 2:
            if(cur != A.end()) cur = A.erase(cur);
            break;
        default:
            break;
        }
    }
    for(int a:A) cout<<a<<endl;
}
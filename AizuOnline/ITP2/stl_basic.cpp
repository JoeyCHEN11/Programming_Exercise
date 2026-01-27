#include <iostream>
#include <vector>

using namespace std;

vector<int> A,B;


int main(){
    for(int i = 0; i<20; i++){
        A.push_back(i);
    }

    vector<int>::iterator i = A.begin();
    cout<<*i<<endl;
    advance(i,2);//iterator 
    cout<<*i<<endl;
    *i = 3000;

    //simplify loop
    for(auto a:A){
        //a is passed-by-value
        a = 30;
        cout<<a<<" ";
    }
    cout<<endl;
    for(auto a:A) cout<<a<<" ";

    // for(auto & a:A){
    //     //a is passed-by-reference
    //     a = 30;
    //     //cout<<a<<" ";
    // }
    // cout<<endl;
    // for(auto a:A) cout<<a<<" ";
    cout<<endl;

    B.insert(B.begin(),A.begin(),A.end());
    cout<<"B: ";
    for(auto b:B) cout<<b<<" ";
    cout<<endl;
    auto cur = B.begin();
    //remove element cur, return the iterator pointing to the next removed element
    cur = B.erase(cur);
    cout<<"Now Cur: "<<*cur<<endl;
    for(auto b:B) cout<<b<<" ";
}
#include <iostream>
#include <list>

using namespace std;

list<int> A;


int main(){
    int q,query,d,p,x;
    auto cur = A.begin();
    //insert the value before cur
    A.insert(cur,2);
    A.insert(cur,3);

    cout<<"A: ";
    for(int a:A) cout<<a<<" ";
    cout<<endl;
    cout<<(cur==A.end()?"yes":"true")<<endl;

    cur = A.insert(cur,4);
    cout<<"A: ";
    for(int a:A) cout<<a<<" ";
    cout<<endl;
    cout<<"Now cur is: "<<*cur<<endl;

    advance(cur,-2);
    cout<<"Now Delete: "<<*cur<<endl;
    //remove element cur, return the iterator pointing to the next element of removed element
    cur = A.erase(cur);
    cout<<"Now cur is: "<<*cur<<endl;

    auto testend = A.end();
    A.erase(testend);
    //for(int a:A) cout<<a<<endl;
    //cout<<*cur<<endl;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 5e5;
vector<int> A {10,3};




int main(){
    A.resize(20);
    cout<<A.size()<<endl;
    cout<<A[3]<<endl;
    auto i = A.begin();
    i++;
    i++;
    cout<<(i==A.end()?"i is at the end":"i is not at the end")<<endl;
    cout<<A.size()<<endl;

    A.push_back(1);
    A.push_back(3);
    A.push_back(4);
    i = A.begin();
    auto i2 = A.end();
    i2--;
    cout<<"i: "<<*i<<" i2: " << *(i2)<<endl;
    

    //only switch the corresponding value in A[] without changing iterator's position
    iter_swap(i,i2);
    cout<<"swap, now:"<<endl<<"i: "<<*i<<" i2: " << *(i2)<<endl;
    cout<<"A:";
    for(auto a:A){
        cout<<" "<<a;
    }
    
    cout<<endl;
    swap(A.back(),A[1]);
    for(auto a:A){
        cout<<" "<<a;
    }
}
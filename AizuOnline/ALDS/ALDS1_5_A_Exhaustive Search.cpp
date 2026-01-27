#include <iostream>
using namespace std;
int n;
int A[20];
bool findSum(int i,int sum){
    if(sum==0) return true;
    if(sum<0||i==n) return false;
    //利用运算符||的特性（第一个为true则直接返回true不计算第二个表达式）提升可读性
    return findSum(i+1,sum-A[i])||findSum(i+1,sum);
}

int main(){
    int q,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>m;
        if(findSum(0,m)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}

/*复健
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;
int A[20] = {0};
int n,q;

bool pick_check(int i,int m){
    if(m == 0) return true;
    if(m<=0 || i>=n) return false;
    else {
        return pick_check(i+1, m)||pick_check(i+1,m-A[i]);
    }
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    cin>>q;
    for(int i = 0; i < q; i++){
        int m;
        cin>>m;
        if(pick_check(0,m)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        
    }

}

*/
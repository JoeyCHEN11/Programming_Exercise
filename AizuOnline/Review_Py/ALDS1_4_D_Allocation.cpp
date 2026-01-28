#include <iostream>
using namespace std;
typedef long long llong;
const int MAX=100000;
const llong MAXP = 100000 * 10000;

llong N[MAX];
int k,n;
int checkV(llong P){
    int i=0;
    for(int j=0;j<k;j++){
        llong s=0;
        //给每辆卡车装货
        while(s+N[i]<=P){
            s+=N[i];
            i++;
            //如果装完则返回n
            if(i==n) return n;
        }
    }
    //未装完返回最多能装的数量
    return i;
}
int solveP(){
    llong midP, leftP = 0, rightP = MAXP;
    while(leftP<rightP){
        midP=(leftP+rightP)/2;
        //如果能装完，说明当前midP较大或正好为最小值
        if(checkV(midP)==n) rightP=midP;
        //不能装完说明当前mid较小
        else leftP=midP+1;
    }
    return rightP;
}
int main(){
    int P;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>N[i];
    }
    P=solveP();
    cout<<P<<endl;
    return 0;
}

/* 复健
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;
const long long MAXP = 10000 * 100000;
const int MAXN = 100000;
int packages[MAXN] = {0};
int n,k;//n:pacagenum, k:trucknum

int checkv(long long P){//given P, get max package number v with k trucks 
    int v = 0;
    for(int i = 0; i<k; i ++){
        long long s = 0;
        while(s + packages[v] <= P){
            //load the package
            s += packages[v];
            v++;
            if(v==n) return v;
        }
    }
    return v;
}

long long findMinP(){//find P from 0 to MAXP
    long long left = 0;
    long long right = MAXP;
    long long mid = 1 ;
    while(right-left > 1){
        mid = (left+right)/2;
        //v must be less or equal to n
        if(checkv(mid)==n) right = mid;
        else left = mid;
    }
    return right;
}

int main(){
    //int n,k,w;
    cin>>n>>k;
    for(int i = 0; i<n; i++){
        cin>>packages[i];
    }

    long long minP = findMinP();
    cout<<minP<<endl;    
}
*/
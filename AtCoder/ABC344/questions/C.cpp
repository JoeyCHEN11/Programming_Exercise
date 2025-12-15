#include <unordered_set>
#include <iostream>

using namespace std;

const int MAXN = 100;
int A[MAXN] {0};
int B[MAXN] {0};
int C[MAXN] {0};

void sumABC(){
    
    int n, m, l, q;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>A[i];
    cin>>m;
    for(int i = 0; i < m; i++) cin>>B[i];
    cin>>l;
    for(int i = 0; i < l; i++) cin>>C[i];

    unordered_set<int> ab, check;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ab.insert(A[i] + B[j]);
        }
    }
    
    for(int i; i < l; i++){
        for(auto sum : ab){
            check.insert(C[i] + sum);
        }
    }

    cin>>q;
    int sum;
    while(q--){
        cin>>sum;
        cout<<(check.find(sum) == check.end()? "No":"Yes")<<endl; 
    }

}
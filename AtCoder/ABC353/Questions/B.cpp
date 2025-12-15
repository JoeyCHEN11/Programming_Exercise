#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> que;

int guide(){
    int atc = 0;
    int seat = k;
    while(true){
        if(que.empty()){
            atc++;
            break;
        }

        if(seat < que.back()){
            atc++;
            seat = k;
        }else{
            seat -= que.back();
            que.pop_back();
        }
    }
    return atc;
}

int main(){
    cin>>n>>k;
    que.resize(n);
    for(int i = n - 1; i >= 0; i--) cin>>que[i];

    cout<<guide()<<endl;

}
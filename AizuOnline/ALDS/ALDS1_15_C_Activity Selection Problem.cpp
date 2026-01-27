#include <bits/stdc++.h>

using namespace std;

struct activity{
    int s;
    int f;
    bool operator < (const activity & a) const { return this->f < a.f; } 
};

vector<activity> acts;
int n;

int greedySelector(){
    int cnt = 0;
    int f = 0;
    for(int i = 0; i < n; i++){
        if(acts[i].s > f){
            cnt++;
            f = acts[i].f;
        }
    }
    return cnt;
}


int main(){
    cin>>n;
    acts.resize(n);

    for(int i = 0; i < n; i++) {
        cin>>acts[i].s;
        cin>>acts[i].f;
    }
    sort(acts.begin(), acts.end());
    cout<<greedySelector()<<endl;
}

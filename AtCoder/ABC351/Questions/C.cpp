#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> A;

int mergeBalls(){
    vector<int> st;

    for(auto a : A){
        while(!st.empty() && st.back() == a){
            st.pop_back();
            a++;
        }
        st.push_back(a);
    }

    return st.size();
}

int main(){
    cin>>n;
    A.resize(n);
    for(auto& a : A){
        cin >> a;
    }
    cout<<mergeBalls()<<endl;
}
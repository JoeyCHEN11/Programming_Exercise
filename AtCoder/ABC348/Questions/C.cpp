#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> beans;

int worstOfBest(){
    unordered_map<int, int> mins;

    for(auto [a, c] : beans){
        if(mins.count(c)){
            mins[c] = min(mins[c], a);
        }else{
            mins[c] = a;
        }
    }

    return max_element(mins.begin(), mins.end(), [](auto & p1, auto & p2) -> bool{
        return p1.second < p2.second;
    })->second;

}

int main(){
    cin>>n;
    beans.resize(n);
    for(auto & [a, c] : beans) cin>>a>>c;

    cout<<worstOfBest()<<endl;


}
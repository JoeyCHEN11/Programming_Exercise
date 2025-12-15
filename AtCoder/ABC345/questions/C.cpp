#include <iostream>
#include <unordered_map>


using namespace std;

long long oneTimeSwap(string & s){
    unordered_map<char, int> check;
    long long ans = 0;
    for(char c : s) {
        check[c]++;
        if(check[c] > 1) ans = 1;
    }
    for(auto i = check.begin(); i != check.end(); i++){
        //cout<<(i->first);
        //cout<<endl;
        for(auto j = next(i); j != check.end(); j++){
            //cout<<j->first;
            ans += i->second * j->second;
        }
        //cout<<endl;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<oneTimeSwap(s)<<endl;
}
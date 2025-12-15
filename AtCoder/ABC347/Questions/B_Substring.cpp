#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

int countSubstr(string s){
    int n = s.size();
    int cnt = 0;
    unordered_set<string> check;
    for (int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++){
            string sub = s.substr(i, j - i);
            if(!check.count(sub)){
                check.insert(sub);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    string s;
    cin>>s;
    cout<<countSubstr(s)<<endl;

    return 0;
}

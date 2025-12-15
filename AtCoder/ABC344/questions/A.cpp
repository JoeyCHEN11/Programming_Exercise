#include <string>

using namespace std;

string spoiler(string s){
    int n = s.size();
    string ans;
    int i = 0;
    while(s[i] != '|') {
        ans.push_back(s[i]);
        i++;
    }
    do{
        i++;
    }while(s[i] != '|');

    i++;
    while(i < n) ans.push_back(s[i++]);

    return ans;
}
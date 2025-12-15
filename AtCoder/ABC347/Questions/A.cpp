#include <vector>
#include <iostream>

using namespace std;

void divisible(){
    vector<int> ans;
    int n, k;
    
    cin>>n>>k;

    int num;
    while(n--){
        cin>>num;
        if(num % k == 0) ans.push_back(num / k);
    }

    for(auto d : ans){
        cout<<d<<" ";
    }
    cout<<endl;
}

int main(){
    divisible();

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void delimiter(){
    vector<int> nums;
    int a;
    cin>>a;
    nums.emplace_back(a);
    
    while(a != 0){
        cin>>a;
        nums.emplace_back(a);
    }

    for(auto i = nums.rbegin(); i != nums.rend(); i++) cout<<*i<<endl;

}
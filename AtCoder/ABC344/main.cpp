#include "questions\E.cpp"

using namespace std;

int main(int, char**){
    int n, a, q;
    list<int> nums;
    cin>>n;
    while(n--){
        cin>>a;
        nums.emplace_back(a);
    }
    cin>>q;
    insertOrErase(nums, q);


    for(auto i = nums.begin(); i != nums.end(); i++){
        cout<<*i;
        if(i != nums.end()) cout<<' ';
    }
    cout<<endl;
}

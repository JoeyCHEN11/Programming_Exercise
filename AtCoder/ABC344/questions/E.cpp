#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void insertOrErase(list<int> & nums, int q){
    int type, x, y;
    while(q--){
        cin>>type>>x;
        auto i = find(nums.begin(), nums.end(), x);
        if(type == 1){
            cin>>y;
            nums.insert(next(i), y);
        }else{
            nums.erase(i);
        }
    }
}
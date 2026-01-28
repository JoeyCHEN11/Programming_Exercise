#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    set<int> S;
    srand(time(nullptr));
    for(int i = 0; i < 20; i++){
        int ran_e = rand()%100;
        cout<<"insert "<<ran_e<<endl;
        if(S.find(ran_e)!=S.end()) cout<<"duplicated"<<endl;
        S.insert(ran_e);
    }
    S.insert(101);
    S.insert(100);
    auto i = S.find(100);
    i = S.erase(i);
    cout<<"delete 100, i: "<<*i<<endl;
    for(int s:S){
        cout<<s<<" ";
    }
    cout<<endl;
    S.clear();
    if(S.empty()){
        cout<<"set clear"<<endl;
    }
    
    /* code */
    return 0;
}

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    map<int, string> M;
    srand(time(nullptr));
    string num;
    for(int i = 0; i < 20; i++){

        pair<int, string> ran_e = make_pair(rand()%100, "data " + to_string(i));
        cout<<"insert <"<<ran_e.first<<", "<<ran_e.second<<">";
        if(M.find(ran_e.first)!=M.end()) {
            cout<<" duplicated";
        }else M.insert(ran_e);
        cout<<endl;
    }
    
    M.insert(make_pair(100,"100 data"));
    
    auto i = M.find(100);
    //i = M.erase(i);
    cout<<"delete 100, i: "<<(*i).first<<", "<<(*i).second<<endl;

    cout<<"now M: "<<endl;
    for(auto m:M){
        cout<<m.first<<", "<<m.second<<endl;
    }
    cout<<endl;
    cout<<M[100];
    M.clear();
    if(M.empty()){
        cout<<"set clear"<<endl;
    }

    map<int,int> empty_M;
    cout<<"now test empty map:"<<endl;
    cout<<"size: "<<empty_M.size()<<endl;
    cout<<empty_M[1]<<endl;
    cout<<"size: "<<empty_M.size()<<endl;
    /* code */
    return 0;
}

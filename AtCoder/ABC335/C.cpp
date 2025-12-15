#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    vector<pair<string, string>> queries;
    unordered_map<string, pair<int, int>> directs;
    directs["R"] = {1, 0};
    directs["L"] = {-1, 0};
    directs["U"] = {0, 1};
    directs["D"] = {0, -1};

    for(int i = 0; i < q; i++){
        string type, query;
        cin>>type>>query;
        queries.push_back({type, query});
    }

    deque<pair<int, int>> loong;
    for (int i = 1; i <= n; i++) loong.emplace_back(i, 0);

    for (auto [type, query] : queries){
        if (type == "1"){
            auto [x, y] = loong.front(); loong.pop_back();
            auto [dx, dy] = directs[query];
            loong.push_front({x + dx, y + dy});
        }else{
            auto [x, y] = loong[stoi(query) - 1];
            cout<<x<<' '<<y<<endl;
        }
    }
}
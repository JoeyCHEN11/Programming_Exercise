#include <bits/stdc++.h>

using namespace std;

unordered_map<char, pair<int, int>> dir;
int h, w, n;
string moves;
vector<string> grid;

void init(){
    dir['L'] = {0, -1};
    dir['R'] = {0, 1};
    dir['U'] = {-1, 0};
    dir['D'] = {1, 0};
}

bool boundCheck(int i, int j){ return i > 0 && i < h - 1 && j > 0 && j < w - 1; }

int cntPos(){
    int cnt = 0;

    for(int i = 1; i < h - 1; i++){
        for(int j = 1; j < w - 1; j++){

            if(grid[i][j] == '.'){
                bool flag = true;
                int ui = i, uj = j;
                for(auto c : moves){
                    auto [dx, dy] = dir[c];
                    ui += dx;
                    uj += dy;
                    if(!boundCheck(ui, uj) || grid[ui][uj] == '#'){
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
            }

        }
    }
    return cnt;
}


int main(){
    cin>>h>>w>>n;
    cin>>moves;
    grid.resize(h);
    init();
    for(auto & s : grid) cin>>s;

    cout<<cntPos()<<endl;


}
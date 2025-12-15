#include <bits/stdc++.h>

using namespace std;

int dir[4][2] { -1, 0, 0, 1, 1, 0, 0, -1};
vector<vector<bool>> grid;
int h, w, n;

void init(){
    cin>>h>>w>>n;
    grid.resize(h, vector<bool>(w, true));
}

void rotate(int & face, bool clock){
    if(clock){
        face = (face + 1) % 4;
    }else{
        face = face == 0? 3 : face - 1;
    }
}

void moveForward(int & i, int & j, int face){
    auto [dx, dy] = dir[face];

    i = (i + dx) % h;
    j = (j + dy) % w;

    if(i < 0) i = h - 1;
    if(j < 0) j = w - 1;

}

void paint(){
    int face = 0;
    int i = 0, j = 0;
    
    for(int x = 0; x < n; x++){
        if(grid[i][j]){
            grid[i][j] = false;
            rotate(face, true);
            moveForward(i, j, face);
        }else{
            grid[i][j] = true;
            rotate(face, false);
            moveForward(i, j, face);
        }
    }
}

int main(){
    init();
    paint();
    for(auto & line : grid){
        for (auto isWhite : line) {
            cout<<(isWhite? '.' : '#');
        }
        cout<<endl;
    }

}

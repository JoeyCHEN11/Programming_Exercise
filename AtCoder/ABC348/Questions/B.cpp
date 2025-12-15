#include <bits/stdc++.h>

using namespace std;


double distance(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

vector<double> dist;
//      x, y;
vector<pair<int, int>> points;
vector<int> ans;
int n;

void getFarPoint(){
    for(int i = 0; i < n; i++){
        auto [x1, y1] = points[i];
        for(int j = i + 1; j < n; j++){
            auto [x2, y2] = points[j];
            double d = distance(x1, y1, x2, y2);
            if(d > dist[i]){
                dist[i] = d;
                ans[i] = j;
            }
            if(d > dist[j]){
                dist[j] = d;
                ans[j] = i;
            }
        }
    }

}


int main(){
    cin>>n;
    dist.resize(n, 0);
    ans.resize(n);
    points.resize(n);

    for(auto & p : points) cin>>p.first>>p.second;

    getFarPoint();

    for(auto a : ans){
        cout<<a + 1<<endl;
    }
    
}


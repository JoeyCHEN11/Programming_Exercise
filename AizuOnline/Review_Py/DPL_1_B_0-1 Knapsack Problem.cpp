#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static const int MAXN = 100 + 1;
static const int MAXW = 10000 + 1;


int Check_Value[MAXN][MAXW] = {0};
bool Diagonal[MAXN][MAXW] = {false};
void init(int w){
    for(int i = 0; i <= w; i ++) {
        Check_Value[0][i] = 0;
        Diagonal[0][i] = true;
    }
}


//item second: weight, first: value
int get_value_dp(int w, const vector<pair<int, int>> & items){
    init(w);
    int n = items.size() - 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){

            // if(j < items[i].second) Check_Value[i][j] = Check_Value[i - 1][j];
            // //0-1背包问题中，需要检查上一行（n-1物品为止)的最优解判断是否选择当前物品，而当物品重复可选(重复背包问题)时，需要改为到n为止的最优解来判断，见coin问题
            // //                                        ↓here
            // else Check_Value[i][j] = max(Check_Value[i - 1][j - items[i].second] + items[i].first, Check_Value[i - 1][j]);

            Check_Value[i][j] = Check_Value[i - 1][j];
            Diagonal[i][j] = false;
            if(j >= items[i].second && items[i].first + Check_Value[i - 1][j - items[i].second] > Check_Value[i - 1][j]){
                Check_Value[i][j] = items[i].first + Check_Value[i - 1][j - items[i].second];
                Diagonal[i][j] = true;
            }
        }
    }
    return Check_Value[n][w];
}

void get_selection(const vector<pair<int, int>>& items, int N, int W){
    vector<int> selection;
    for(int i = N, w = W; i >= 1; i--){
        if(Diagonal[i][w]) {
            selection.push_back(i);
            w -= items[i].second;
        }
    }
    
    reverse(selection.begin(), selection.end());
    cout<<"select: "<<endl;
    for(int i : selection){
        cout<<"item["<<i<<"]: weight: "<< items[i].second<<", value: "<<items[i].first<<endl;
    }
}


int main(int argc, char const *argv[])
{
    
    int n, w;
    vector<pair<int, int>> items;
    cin>>n>>w;
    items.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>items[i].first>>items[i].second;
    }
    cout<<get_value_dp(w, items)<<endl;


    //get_selection(items, n, w);

    return 0;
}

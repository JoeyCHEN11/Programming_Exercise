/**
 * KamaCoder_52.携带研究材料(KnapsackProblem)
 * 
 * 题目描述
 *  小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。
 *  他需要带一些研究材料，但是他的行李箱空间有限。
 *  这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的重量，并且具有不同的价值。
 *  小明的行李箱所能承担的总重量为 N，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料可以选择无数次，并且可以重复选择。
 * 
 * 输入描述
 *  第一行包含两个整数，N，V，分别表示研究材料的种类和行李空间
 *  接下来包含 N 行，每行两个整数 wi 和 vi，代表第 i 种研究材料的重量和价值
 * 
 *  输出一个整数，表示最大价值。
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int m, n;
    cin>>m>>n;

    // 2D array
    // vector<pair<int, int>> items(m + 1, {0,0});
    // for(int i = 1; i <= m; i++) cin>>items[i].first>>items[i].second;
    // vector<vector<int>> knapsack(m + 1, vector<int> (n + 1, 0));
    // for(int i = 1; i <= m; i++){
    //     auto [weight, value] = items[i];
    //     for (int j = 1; j <= n; j++){
    //         if(j < weight) knapsack[i][j] = knapsack[i-1][j];
    //         else knapsack[i][j] = max(knapsack[i - 1][j], knapsack[i][j - weight] + value);
    //     }
    // }

    // optimize 1D space
    vector<pair<int, int>> items(m, {0,0});
    for(auto& item : items) cin>>item.first>>item.second;
    vector<int> knapsack1D(n + 1, 0);
    for(auto item : items){
        auto [weight, value] = item;
        for (int j = weight; j <= n; j++){
            knapsack1D[j] = max(knapsack1D[j], knapsack1D[j - weight] + value);
        }
    }

    cout<<knapsack1D[n]<<endl;
}
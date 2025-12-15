/**
 * KamaCoder_46. 携带研究材料（0-1 Knapsack）
 * 
 * 题目描述
 *  小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。
 *  他需要带一些研究材料，但是他的行李箱空间有限。这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的空间，并且具有不同的价值。 
 *  小明的行李空间为 N，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料只能选择一次，并且只有选与不选两种选择，不能进行切割。
 *
 *  第一行包含两个正整数，第一个整数 M 代表研究材料的种类，第二个正整数 N，代表小明的行李空间。
 *  第二行包含 M 个正整数，代表每种研究材料的所占空间。 
 *  第三行包含 M 个正整数，代表每种研究材料的价值。
 * 
 *  输出一个整数，代表小明能够携带的研究材料的最大价值。
 * 
 *  
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int m, n;
    cin>>m>>n;
    vector<int> weights(m + 1, 0);
    vector<int> values(m + 1, 0);

    for(int i = 1; i <= m; i++) cin>>weights[i];
    for(int i = 1; i <= m; i++) cin>>values[i];

    // vector<vector<int>> knapsack(m + 1, vector<int> (n + 1, 0));
    // for(int i = 1; i <= m; i++){
    //     for (int j = 1; j <= n; j++){
    //         if(j < weights[i]) knapsack[i][j] = knapsack[i-1][j];
    //         else knapsack[i][j] = max(knapsack[i - 1][j], knapsack[i - 1][j - weights[i]] + values[i]);
    //     }
    // }
    // cout<<knapsack[m][n]<<endl;

    vector<int> knapsack1D(n + 1, 0);
    for(int i = 1; i <= m; i++){
        for (int j = n; j >= weights[i]; j--){
            knapsack1D[j] = max(knapsack1D[j], knapsack1D[j - weights[i]] + values[i]);
        }
    }
    cout<<knapsack1D[n]<<endl;
}
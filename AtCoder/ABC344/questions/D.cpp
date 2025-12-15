#include <string>
#include <vector>
#include <iostream>

using namespace std;

int stringBags(vector<vector<string>> & bag, string & t, int n){
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    fill(dp[0].begin() + 1, dp[0].end(), INT32_MAX);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            for(string word : bag[i - 1]){
                if(word.size() > j) continue;
                if(t.substr(j - word.size(), word.size()) == word && dp[i - 1][j - word.size()] != INT32_MAX){
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - word.size()] + 1);
                }
            }
        }
    }

    return dp[n][m] == INT32_MAX? -1 : dp[n][m];
}

// int main(int, char**){
//     int n,len;
//     string t;
//     vector<vector<string>> bag;
//     cin>>t>>n;
    
//     for(int i = 0; i<n; i++){
//         cin>>len;
//         vector<string> item;
//         string s;
//         while(len--){
//             cin>>s;
//             item.emplace_back(s);
//         }
//         bag.emplace_back(item);
//     }

//     cout<<stringBags(bag, t, n)<<endl;
// }

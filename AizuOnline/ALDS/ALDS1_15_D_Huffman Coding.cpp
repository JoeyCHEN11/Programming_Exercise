#include <bits/stdc++.h>

using namespace std;

// struct node{
//     char key;
//     char left, right;
//     int freq;
//     bool operator < ()
// };

int check[26] {0};
string s;

int huffman(){
    int cost = 0; 
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int freq : check){
        if(freq > 0) pq.push(freq);
    }
    
    if(pq.size() == 1) return pq.top();

    while(pq.size() > 1){
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        cost += x + y;
        pq.push(x + y);
    }

    return cost;
}

int main(){
    cin>>s;
    for(char c : s) check[c - 'a']++;
    cout<<huffman()<<endl;

}

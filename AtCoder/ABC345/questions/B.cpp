// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void bigIntDivision(vector<int> & a, bool pos){
//     if(a.back() == 0 || !pos) {
//         a.pop_back();
//         return;
//     }
//     a.pop_back();
//     if(a.empty()){
//         a.push_back(1);
//         return;
//     }
//     reverse(a.begin(), a.end());
//     int n = a.size();
//     int carry = (a[0] + 1) / 10;
//     a[0] = (a[0] + 1) % 10;
//     for(int i = 1; i < n && carry == 1; i++){
//         carry = (a[i] + 1) / 10;
//         a[i] = (a[i] + 1) % 10;
//     }
//     if(carry == 1) a.push_back(1);
//     reverse(a.begin(), a.end());
// }

// int main(){
//     char sign, bit;
//     vector<int> a;
//     cin>>sign;
//     if(sign != '-') a.emplace_back(sign - '0');
//     while(cin>>bit){
//         a.emplace_back(bit - '0');
//     }
//     //for(int i : a) cout<<i;
//     //cout<<endl;
//     bigIntDivision(a, sign != '-');
//     if(a.empty()) cout<<0<<endl;
//     else{
//         if(sign == '-') cout<<sign;
//         for(int i : a) cout<<i;
//         cout<<endl;
//     }
//  }

 #include <iostream>

using namespace std;

long long divCeil(long long a, long long div){ return (a>=0? a + div - 1 : a)/div; }
int main(){
    long long a;
    cin>>a;
    cout<<divCeil(a, 10)<<endl;
}
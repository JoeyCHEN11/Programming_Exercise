#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static const int MAXN = 1e5 + 1;


//Length[i]: the length of lis within A[1~i], and A[i] is selected
int Length[MAXN] = {0};
//Previous[i]: the second last element of the lis defined in Length[i]
int Previous[MAXN] = {0};
//O(n^2)
int lis_dp(vector<int>& A){
    int n = A.size() - 1;
    Length[0] = 0;
    A[0] = -1;
    Previous[0] = -1;
    int max_idx = 0;
    for(int i = 1; i<=n; i++){
        int pre_idx = 0;
        for(int j = 0; j<i; j++){
            if(A[j] < A[i] && Length[j] > Length[pre_idx]){
                pre_idx = j;
            }
        }
        Length[i] = Length[pre_idx] + 1;
        Previous[i] = pre_idx;
        max_idx = Length[i] > Length[max_idx]? i:max_idx;
    }

    return max_idx;
}

void print_lis(int lis_last, const vector<int> & A){
    cout<<"lis len: Length["<<lis_last<<"]: "<<Length[lis_last]<<endl;
    cout<<"select:"<<endl;
    for(int i = lis_last; Length[i]>0; i = Previous[i]){
        cout<<"A["<<i<<"]: "<<A[i]<<endl;
    }
}

//L[i]: the last-and-minimum element of the increasing subsequence with length i+1
int L[MAXN] = {0};
//idx start from 0
//O(nlogn)
int lis_greedy_bisearch(const vector<int>& A){
    int n = A.size() - 1;
    L[0] = A[0];
    int lis_len = 1;
    for(int i = 1; i < n; i++){
        if(A[i] > L[lis_len - 1]){
            L[lis_len++] = A[i];
        }else {
            // if((lis_len<=1 || A[i]>L[lis_len-2])) 
            // L[lis_len - 1] = A[i]; 
            *lower_bound(L,L+lis_len,A[i]) = A[i];
        }
    }
    return lis_len;
}

int main(int argc, char const *argv[])
{
    
    int n;
    vector<int> A;
    cin>>n;
    A.resize(n+1);

    //dp
    // for(int i = 1; i <= n; i++){
    //     cin>>A[i];
    // }
    //int lis_last = lis_dp(A);
    //print_lis(lis_last, A);
    //cout<<Length[lis_last]<<endl;


    //dp + bisearch
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    cout<<lis_greedy_bisearch(A)<<endl;
    return 0;
}

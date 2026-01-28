#include <iostream>
#include <algorithm>

using namespace std;
const int MAXSIZE = 2e5;
const int INF = 1e9+5;

int A[MAXSIZE];
int L[MAXSIZE/2 + 1];
int R[MAXSIZE/2 + 1];
//long long inversionCounter = 0;

/**
 * @brief merge the sorted L and R, then count new inversions between two segments
 * 
 * @param left 
 * @param mid 
 * @param right 
 * @return long long 
 */
long long mergeAndCount(int left, int mid, int right){
    long long counter = 0;
    int n_left = mid - left;
    int n_right = right - mid;
    for(int i = 0; i < n_left; i++) L[i] = A[left+i];
    for(int i = 0; i < n_right; i++) R[i] = A[mid+i];
    L[n_left] = INF; R[n_right] = INF; 
    for(int i = 0, j = 0, k = left; k < right; k++){
        //L[i] > R[j] implies that all elements after L[i](include L[i]) > R[j]
        if(L[i]>R[j]){
            A[k] = R[j];
            //so R[j] have n_left-i inversions in L segment
            counter += n_left - i;//mid-k+j; ( k-(i+j) == left )// 
            j++;
        }
        else{
            A[k] = L[i];
            i++;
        }
    }
    return counter;
}

long long mergeSort(int left, int right){
    int long long cnt = 0;
    if(left + 1 < right){
        int mid = (left+right)/2;
        long long left_cnt = mergeSort(left,mid);
        long long right_cnt = mergeSort(mid,right);
        cnt += mergeAndCount(left,mid,right) + left_cnt + right_cnt;
    }
    return cnt;
}


int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>A[i];
    }
    
    long long ans = mergeSort(0,n);
    cout<<ans<<endl;
}
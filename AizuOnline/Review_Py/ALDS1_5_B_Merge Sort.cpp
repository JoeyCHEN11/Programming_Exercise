#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdio>

typedef long long llong;

using namespace std;

const int MAXSIZE = 500000;
const int INF = 1e9+5;
int S[MAXSIZE] = {0};
int L[MAXSIZE/2 + 1] = {0};
int R[MAXSIZE/2 + 1] = {0};
int counter = 0;
/**
 * @brief combine two sotred half-parts [left, mid) and [mid, right)
 * 
 * @param left 
 * @param mid 
 * @param right 
 */
void merge(int left, int mid, int right){
    int n_left = mid - left; //size of left (mid not included)
    int n_right = right - mid; //size of right (right not included)
    for(int i = 0; i < n_left; i++) L[i] = S[left + i];
    for(int i = 0; i < n_right; i++) R[i] = S[mid + i];
    // set sentinels
    L[n_left] = INF; 
    R[n_right] = INF;
    for(int i = 0, j = 0, k = left; k < right; k++){
        counter++;
        if(L[i] <= R[j]){
            S[k] = L[i];
            i++;
        }
        else{
            S[k] = R[j];            
            j++;
        }
    }
    return;
}

/**
 * @brief divide an array from [left, right) to [left, mid) and [mid, right), then merge into a sorted array
 * 
 * @param left 
 * @param right 
 */
void mergeSort(int left, int right){
    if(right - left > 1){
        int mid = (right + left) / 2;

        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        scanf("%d", &S[i]);
    }
    mergeSort(0,n);
    for(int i = 0; i < n -1; i++){
        printf("%d ",S[i]);
    }
    cout<<S[n-1]<<endl<<counter<<endl;
    return 0;
}

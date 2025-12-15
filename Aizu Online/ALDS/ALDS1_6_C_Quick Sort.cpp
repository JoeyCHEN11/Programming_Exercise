#include <iostream>
#include <algorithm>

using namespace std;
const int MAXSIZE = 1e5;
const int INF = 1e9+5;
typedef struct _card{
    char suit;
    int value;
}card;
card A[MAXSIZE];
card stable_A[MAXSIZE];
card L[MAXSIZE/2 + 1];
card R[MAXSIZE/2 + 1];


int partition1(int p, int r){
    int x = A[r].value;
    int i = p;
    int j = r-1;
    do{
        while(A[i].value < x) i++;
        while(A[j].value >= x && i < j) j--;
        if(i<j) swap(A[i],A[j]);
    }while(i<j);
    swap(A[i],A[r]);
    return i;
}

/**
 * @brief partition of an array contains 3 parts:
 *        A1[p,p+1,...,q-1], A[q], A2[q+1,q+2,...,r].
 *        A[q] is the pivot, where A[q] >= a:A1 and A[q] < a:A2.
 *        this function will pick the last element as the pivot
 * @param p 
 * @param r 
 * @return int the final index of the pivot
 */
int partition2(int p, int r){
    int x = A[r].value;
    //i group: all elements which <= x
    int i = p-1;
    for(int j = p; j<r; j++){//check j group: all elements after i group, which > x
        if(A[j].value<=x){
            i++;
            swap(A[i],A[j]);//swap it to the i group
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quickSort(int left, int right){
    if(left<right){
        int pivod_idx= partition2(left, right);
        quickSort(left, pivod_idx-1);
        quickSort(pivod_idx+1,right);
    }
    return;
}

void merge(int left, int mid, int right){
    int n_left = mid - left; //size of left (mid not included)
    int n_right = right - mid; //size of right (right not included)
    for(int i = 0; i < n_left; i++) L[i] = stable_A[left + i];
    for(int i = 0; i < n_right; i++) R[i] = stable_A[mid + i];
    // set sentinels
    L[n_left].value = INF; 
    R[n_right].value = INF;
    for(int i = 0, j = 0, k = left; k < right; k++){
        if(L[i].value <= R[j].value){
            stable_A[k] = L[i];
            i++;
        }
        else{
            stable_A[k] = R[j];            
            j++;
        }
    }
    return;
}

void mergeSort(int left, int right){
    if(left + 1 < right ){
        int mid = (right + left) / 2;

        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
    return;
}

bool isStable(int n){
    for(int i = 0; i < n; i++){
        if(A[i].suit!=stable_A[i].suit) return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>A[i].suit>>A[i].value;
        stable_A[i].suit = A[i].suit;
        stable_A[i].value = A[i].value;
    }
    mergeSort(0,n);
    quickSort(0,n-1);
    if(isStable(n)) cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;
    for(int i = 0; i<n; i++){
        cout<<A[i].suit<<" "<<A[i].value<<endl;
    }
}
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXSIZE = 1e3;
const int MAXV = 1e4;
int A[MAXSIZE] = {0};
int sorted_A[MAXSIZE] = {0};
int check_sorted_idx[MAXV+1] = {0};
bool check_cirtuit[MAXSIZE] = {0};

int solve_min_cost(int n){
    int ans = 0;
    int w_min = sorted_A[0];
    //cout<<w_min<<endl;
    for(int i = 0; i<n; i++){
        //count each circuit;
        //true value implies that the element was    solved as a cirtuit before
        if(check_cirtuit[i]) continue;
        int el_pos = i;
        int sum_w = 0;
        int w_local_min = MAXV;
        int circuit_n = 0;
        do{
            circuit_n++;
            check_cirtuit[el_pos] = true;
            int x = A[el_pos];
            sum_w += x;
            //find the correct idx of the current element(A[i]) where it should be in the sorted A
            //so we can check that position back into unsorted A, which can be a member of the current circuit
            //(because if the current value of A is not on its correct position, then (at least) the value on its correct position shoule be swaped with it, which implies that they are all the members of the current cirtuit) 
            el_pos = check_sorted_idx[x];
            w_local_min = min(w_local_min,x);
            //if we find that the check table is true, it implies that the traversal of the current cirtuit is finished
        }while(!check_cirtuit[el_pos]);
        //and we are going to find the next cirtuit after calculating the min  cost
        ans += min(sum_w+(circuit_n-2)*w_local_min, sum_w+(circuit_n+1)*w_min+w_local_min);
    }
    return ans;
}


int main(){
    int n,w;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>w;
        A[i] = w;
        sorted_A[i] = w;

    }
    sort(sorted_A,sorted_A+n);
    for(int i = 0; i<n; i++) check_sorted_idx[sorted_A[i]] = i;
    // for(int a:sorted_A) cout<<a<<" ";
    // cout<<endl;
    cout<<solve_min_cost(n)<<endl;
}
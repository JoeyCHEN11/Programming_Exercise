#include <iostream>
using namespace std;
void selectSort(int array[],int n){
	int count=0;
	for(int i=0;i<n;i++){
		int minj=i;
		for(int j=i;j<n;j++){
			if(array[minj]>array[j]) minj=j;
		}
		if (minj!=i) count++;
		swap(array[minj],array[i]);
	}
	for(int i=0;i<n-1;i++){
		cout<<array[i]<<" ";
	}
	cout<<array[n-1]<<endl;
	cout<<count<<endl;
}
int main(){
	int n;
	int array[100]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	selectSort(array,n);
}
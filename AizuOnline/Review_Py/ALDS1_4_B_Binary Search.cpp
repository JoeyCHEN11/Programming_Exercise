#include <iostream>

using namespace std;

bool binarySearch(int* array,int n,int value){
	int left=0;
	//鉴于整数除法向下取整，可以给right一个永远不会取到的值，成为border
	int right=n;
	//以便把小于等于换成小于，左闭右开
	while(left<right){
		int mid=(left+right)/2;
		if(value==array[mid]) return true;
		//left照常
		if(value>array[mid]) left=mid+1;
		else right=mid;
	}
	return false;
}

int main(){
	int n;
	int S[100000];
	int q,T;
	int C=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>S[i];
	cin>>q;
	for(int i=0;i<q;i++) {
		cin>>T;
		if(binarySearch(S,n,T)) C++;
	}
	cout<<C<<endl; 
}
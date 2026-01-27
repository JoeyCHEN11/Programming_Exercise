#include <iostream>

using namespace std;

bool search(int* array,int n,int value){
	//在队尾再后面添加一个哨兵
	array[n]=value;
	int i=0;
	while(array[i]!=value) i++;
	return i!=n;

}

int main(){
	int n;
	int S[10001];
	int q,T;
	int C=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>S[i];
	cin>>q;
	for(int i=0;i<q;i++) {
		cin>>T;
		if(search(S,n,T)) C++;
	}
	cout<<C<<endl;
}
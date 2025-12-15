#include <iostream>
using namespace std;

const int N=100;

int main(){
	int count;
	int array[N]={1};
	//cout<<array[0];
	cin>>count;
	for(int i=0;i<count;i++){
		cin>>array[i];
	}
	for(int i=1;i<count;i++){
		for(int m=0;m<count-1;m++){
			cout<<array[m]<<" ";
		}
		cout<<array[count-1]<<endl;

		int insert=array[i];
		int j=i-1;
		while(j>=0&&insert<array[j]){
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=insert;

	}
	for(int m=0;m<count-1;m++){
			cout<<array[m]<<" ";
		}
	cout<<array[count-1]<<endl;

/*
	int count;
	cin>>count;
	int array[count];
	for(int i=0;i<count;i++){
		cin>>array[i];
	}
	for(int i=1;i<count;i++){
		for(int m=0;m<count-1;m++){
			cout<<array[m]<<" ";
		}
		cout<<array[count-1]<<endl;
		int insert=array[i];
		int j;
		for(j=i-1;j>=0&&insert<array[j];j--){
			array[j+1]=array[j];
		}
		array[j+1]=insert;
	for(int m=0;m<count-1;m++){
			cout<<array[m]<<" ";
		}
	cout<<array[count-1]<<endl;
	*/
}
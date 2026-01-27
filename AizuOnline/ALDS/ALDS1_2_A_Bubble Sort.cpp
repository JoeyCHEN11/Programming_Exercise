#include <iostream>
using namespace std;
int main(){
	int count;
	cin>>count;
	int array[100];
	for(int i=0;i<count;i++){
		cin>>array[i];
	}
	int flag=1;
	int counter=0;
	int sorted=0;
	while(flag){
		flag=0;
		for(int i=count-1;i>sorted;i--){
			if(array[i-1]>array[i]){
				swap(array[i],array[i-1]);
				flag=1;
				counter++;
			}
		}
		sorted++;
	}

	/*
	int flag=1;
	int counter=0;
	while(flag){
		flag=0;
		for(int j=count-1;j>0;j--){
			if(array[j]<array[j-1]){
				swap(array[j],array[j-1]);
				flag=1;
				counter++;
			}
		}
	}
	*/
	/* recover:
	#include <iostream>
	using namespace std;

	int main(){
		int N;
		int A[100] = {0};
		int counter = 0;
		cin>>N;
		for(int i = 0; i < N; i++ ){
			cin>>A[i];
		}
		bool isSorted = false;
		for(int i = 0; !isSorted; i++){
			isSorted = true;
			for(int j = N-1; j>i; j--){
				if(A[j]<A[j-1]) {
					swap(A[j],A[j-1]);
					counter++;
					isSorted = false;                                                                                             
				}
			}
		}
		for(int i = 0; i < N; i++ ){
			cout<<A[i]; 
			if(i!=N-1) cout<<" ";
		}
		cout<<endl<<counter<<endl;
		
	}
	*/
	for(int i=0;i<count-1;i++){
		cout<<array[i]<<" ";
	}
	
	cout<<array[count-1]<<endl;
	cout<<counter<<endl;
}
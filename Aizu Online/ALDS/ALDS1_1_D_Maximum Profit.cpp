#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int r0,r1,r;
	cin>>r0>>r1;
	int maxProfit=r1-r0;
	int min=r0<r1? r0:r1;
	//int mini=0;
	for(int i=2;i<n;i++){
	    cin>>r;
		if(r-min>maxProfit) maxProfit=r-min;
		if(r<min) min=r;
	}
	cout<<maxProfit<<endl;
	
}
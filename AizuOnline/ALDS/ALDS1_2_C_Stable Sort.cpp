#include <iostream>

using namespace std;

typedef struct _poker{
    char suit;
    int value;
} poker;

void bubbleSort(poker A[], int N);
void selectSort(poker A[], int N);
bool isStable(poker testA[], poker stableA[], int N);
void printPokers(poker A[], int N);


int main(){
    int N;
    poker bubbleA[36];
    poker selectA[36];
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin>>bubbleA[i].suit>>bubbleA[i].value;
        selectA[i].suit = bubbleA[i].suit;
        selectA[i].value = bubbleA[i].value;
        
    }
    
    bubbleSort(bubbleA,N);
    selectSort(selectA,N);
    
    printPokers(bubbleA,N);
    cout<<"Stable"<<endl;
    printPokers(selectA,N);
    if(isStable(selectA,bubbleA,N)) cout<<"Stable"<<endl;
    else cout<<"Not stable"<<endl;
    
    
}


void bubbleSort(poker A[], int N){
    bool isSorted = false;
		for(int i = 0; !isSorted; i++){
			isSorted = true;
			for(int j = N-1; j>i; j--){
				if(A[j].value<A[j-1].value) {
					swap(A[j],A[j-1]);
					isSorted = false;                                                                                             
				}
			}
		}
}

void selectSort(poker A[], int N){
    int minj;
    for(int i = 0; i<N; i++){
        minj = i;
        for(int j = i+1; j<N; j++){
            if(A[j].value<A[minj].value) minj = j;
        }
        if(minj != i) swap(A[minj], A[i]);
    }
    
}

bool isStable(poker testA[], poker stableA[], int N){
    for(int i = 0; i<N; i++){
        if(testA[i].suit != stableA[i].suit) return false;
    }
    return true;
}

void printPokers(poker A[], int N){
    if(N>0){
        cout<<A[0].suit<<A[0].value;
        for(int i = 1; i < N; i++){
            cout<<" "<<A[i].suit<<A[i].value;
        }
        cout<<endl;
    }
}

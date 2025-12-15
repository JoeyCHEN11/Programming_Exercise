#include <iostream>

using namespace std;


char checkGrade(int m, int f, int r){
    if(m==-1||f==-1) return 'F';
    else if(m+f>=80) return 'A';
    else if(m+f>=65) return 'B';
    else if(m+f>=50) return 'C';
    else if(m+f>=30) {
        if(r>=50) return 'C';
        else return 'D';
    }
    return 'F';
}

int main(){
    int m,f,r;
    for(cin>>m>>f>>r; m!=-1||f!=-1||r!=-1; cin>>m>>f>>r){
        cout<<checkGrade(m,f,r)<<endl;
    }
}
#include <string>
#include <iostream>
#include <vector>

using namespace std;

using ull = unsigned long long;
ull X = 0;
ull Y = 0;

bool findXY(int a, int b, int depth, ull c){
    if(c == 0){
        if(a == 0 && b == 0) return true;
        else return false;
    }
    ull mask = 1 << depth;
    ull tempX = X;
    ull tempY = Y;
    if(c & 1){
        X = X | mask;
        if(findXY(a - 1, b, depth + 1, c >> 1)) return true;
        else{
            X = tempX;
            Y = Y | mask;
            if(findXY(a, b - 1, depth + 1, c >> 1)) return true;
            else {
                Y = tempY;
                return false;
            }
        } 
    }else{
        if(findXY(a , b, depth + 1, c >> 1)) return true;
        else{
            X = X | mask;
            Y = Y | mask;
            if(findXY(a - 1, b - 1, depth + 1, c >> 1)) return true;
            else {
                X = tempX;
                Y = tempY;
                return false;
            }
        } 
    }
}

int main(){
    int a, b;
    ull c;
    cin>>a>>b>>c;
    if(findXY(a, b, 0, c)){
        cout<<X<<" "<<Y<<endl;
    }else cout<<-1<<endl;

}
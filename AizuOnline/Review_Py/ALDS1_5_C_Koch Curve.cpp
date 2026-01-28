#define _USE_MATH_DEFINES 
#include <cstdio>
#include <cmath>

struct point{double x,y;};
void kochCurve(int n,point p1,point p2){
    if(n==0) return;
    point s,u,t;
    s.x=(2*p1.x+p2.x)/3;
    s.y=(2*p1.y+p2.y)/3;
    t.x=(p1.x+2*p2.x)/3; 
    t.y=(p1.y+2*p2.y)/3;
    point sTot;
    sTot.x=t.x-s.x;
    sTot.y=t.y-s.y;
    double theta=M_PI/3;
    u.x=sTot.x*cos(theta)-sTot.y*sin(theta)+s.x;
    u.y=sTot.x*sin(theta)+sTot.y*cos(theta)+s.y;
    
    kochCurve(n-1,p1,s);
    printf("%.8lf %.8lf\n",s.x,s.y);
    kochCurve(n-1,s,u);
    printf("%.8lf %.8lf\n",u.x,u.y);
    kochCurve(n-1,u,t);
    printf("%.8lf %.8lf\n",t.x,t.y);
    kochCurve(n-1,t,p2);
}
int main(){
    int n;
    point p1,p2;
    p1.x=0;
    p1.y=0;
    p2.x=100;
    p2.y=0;
    scanf("%d",&n);
    printf("%.8lf %.8lf\n",p1.x,p1.y);
    kochCurve(n,p1,p2);
    printf("%.8lf %.8lf\n",p2.x,p2.y);
}


//复健：
// #define _USE_MATH_DEFINES
// #include <iostream>
// #include <iomanip>
// #include <cmath>
// using namespace std;

// const double COS60 = cos(M_PI/3);
// const double SIN60 = sin(M_PI/3);
// typedef struct _vec2{
//     double x=0.0;
//     double y=0.0;
// }vec2;

// /**
//  * @brief print the koch curve
//  * 
//  * rotation matrix:
//  * 
//  *      cosa -sina  x
//  *      sina cosa   y
//  * 
//  * 
//  * @param p1 
//  * @param p2 
//  * @param n 
//  */
// void print_kcurve(vec2 p1, vec2 p2, int n){
//     if(n == 0){
//         cout<<fixed<<setprecision(5)<<p2.x<<" "<<p2.y<<endl;
//     }
//     else{ 
//         s.x = (p2.x-p1.x)/3.0 + p1.x;
//         s.y = (p2.y-p1.y)/3.0 + p1.y;
//         t.x = (p2.x-p1.x)*2.0/3 + p1.x;
//         t.y = (p2.y-p1.y)*2.0/3 + p1.y;
//         u.x = COS60*(t.x-s.x) - SIN60*(t.y-s.y) + s.x;
//         u.y = SIN60*(t.x-s.x) + COS60*(t.y-s.y) + s.y;

//         print_kcurve(p1,s,n-1);
//         print_kcurve(s,u,n-1);
//         print_kcurve(u,t,n-1);
//         print_kcurve(t,p2,n-1);
//     }
// }

// int main(){
//     vec2 p1,p2;
//     int n;
//     p1.x = 0;
//     p1.y = 0;
//     p2.x = 100;
//     p2.y = 0;
//     cin>>n;
//     cout<<fixed<<setprecision(6)<<p1.x<<" "<<p1.y<<endl;
//     print_kcurve(p1,p2,n);
// }



#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
static const double EPS = 1e-10; //__DBL_EPSILON__
static const int INF = 1<<30;
enum turn {COUNTER_CLOCKWISE = 1, CLOCKWISE = -1 , ONLINE_BACK = 2, ONLINE_FRONT = -2, ON_SEGMENT = 0};
enum containment { OUT = 0, ON = 1, IN = 2};
enum epos { BOTTOM = 0, LEFT, RIGHT, TOP };
template <typename T>
static const inline bool equals(T a, T b){ return fabs(a - b) < EPS; }

//Point class
class Point
{
public:
    double x,y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    
    Point operator + (const Point & p) const { return Point(x + p.x, y + p.y); }
    Point operator - (const Point & p) const { return Point(x - p.x, y - p.y); }
    Point operator * (double a) const { return Point(x * a, y * a); }
    friend Point operator * (double a, const Point & p) { return p * a ; }
    Point operator / (double a) const { return Point(x / a, y / a); }

    double abs(){ return sqrt(norm()); }
    double norm() { return x * x + y * y;}

    //default: compare x first
    bool operator < (const Point p) const  { return !equals(x,p.x)? x < p.x : y < p.y; }
    bool operator == (const Point & p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
};
bool comp_y (const Point p1, const Point p2 ) { return !equals(p1.y,p2.y)? p1.y < p2.y : p1.x < p2.x; }
using Vector = Point;

struct Segment{
    Point p1, p2;
};
using Line = Segment;

class EndPoint{
public:
    Point p;
    int seg;
    epos pos;

    EndPoint(Point _p = Point(), int _seg = 0, epos _pos = LEFT ): p(_p), seg(_seg), pos(_pos){}

    //comp y 
    bool operator < (const EndPoint& ep) const { return ep.p.y == p.y? pos < ep.pos : p.y < ep.p.y;  }
};


int manhattan_intersection(vector<Segment> s){
    vector<EndPoint> eps;
    
    int n = s.size();
    for(int i =0; i < n; i++) {
        if(s[i].p2 < s[i].p1) swap(s[i].p1, s[i].p2);

        if(s[i].p1.x == s[i].p2.x){
            eps.push_back(EndPoint(s[i].p1, i, BOTTOM));
            eps.push_back(EndPoint(s[i].p2, i, TOP));
        }else{
            eps.push_back(EndPoint(s[i].p1, i, LEFT));
            eps.push_back(EndPoint(s[i].p2, i, RIGHT));
        }
    }
    sort(eps.begin(), eps.end());


    set<int> vertical_segs;
    //vertical_segs.insert(INF);
    int cnt = 0;
    for(int i = 0; i < 2*n; i++ ){
        if(eps[i].pos == BOTTOM) vertical_segs.insert(eps[i].p.x);
        else if(eps[i].pos == TOP) vertical_segs.erase(eps[i].p.x);
        else if(eps[i].pos == LEFT){
            auto left = vertical_segs.lower_bound(s[eps[i].seg].p1.x);
            auto right = vertical_segs.upper_bound(s[eps[i].seg].p2.x);
            // count elements between [left, right) 
            cnt += distance(left, right);
        }
    }
    return cnt;
}


int main(int argc, char const *argv[])
{
    Point p1, p2;
    vector<Segment> segs;
    int x, y;   
    int n;

    cin>>n;
    for(int i = 0; i < n; i ++){
        cin>>x>>y;
        p1 = Point(x, y);
        cin>>x>>y;
        p2 = Point(x, y);
        segs.push_back({p1, p2});
    }
    cout<<manhattan_intersection(segs)<<endl;
    return 0;
}

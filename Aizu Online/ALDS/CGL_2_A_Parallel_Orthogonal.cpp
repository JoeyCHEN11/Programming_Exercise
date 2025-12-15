#include <cmath>
#include <iostream>

using namespace std;
static const  double EPS = 1e-10; //__DBL_EPSILON__

template <typename T>
static const bool equals(T a, T b){ return fabs(a - b) < EPS; }

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

    bool operator < (const Point p) { return x != p.x? x < p.x : y < p.y; }
    bool operator == (const Point & p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
};
using Vector = Point;

double dot(Vector a, Vector b){ return a.x*b.x + a.y*b.y; }
double cross(Vector a, Vector b) { return a.x*b.y - b.x*a.y; }

struct Segment{
    Point p1, p2;
};
using Line = Segment;

bool is_orthogonal(Vector v1, Vector v2){ return equals(dot(v1,v2), 0.0);}
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) { return is_orthogonal(a1 - a2, b1 - b2); }
bool is_orthogonal(Segment s1, Segment s2) { return equals(dot(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0); }

bool is_parallel(Vector v1, Vector v2) { return equals(cross(v1,v2), 0.0); }
bool is_parallel(Point a1, Point a2, Point b1, Point b2) { return is_parallel(a1 - a2, b1 - b2); }
bool is_parallel(Segment s1, Segment s2) { return equals(cross(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0); }


int main(int argc, char const *argv[])
{
    Point a1,a2,b1,b2;
    int q;
    double x,y;

    cin>>q;
    for (int i = 0; i < q; i++){
        cin>>x>>y;
        a1 = Point(x,y);
        cin>>x>>y;
        a2 = Point(x,y);
        cin>>x>>y;
        b1 = Point(x,y);
        cin>>x>>y;
        b2 = Point(x,y);
        if(is_orthogonal({a1, a2},{b1, b2})) cout<<1;
        else if(is_parallel({a1, a2},{b1, b2})) cout<<2;
        else cout<<0;
        cout<<endl;
    }
    


    return 0;
}






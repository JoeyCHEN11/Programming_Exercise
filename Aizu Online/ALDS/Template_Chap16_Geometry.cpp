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




int main(int argc, char const *argv[])
{
    Point p(3.2,3);
    Vector e1(1,0);
    p = 2 * p;
    cout<<p.x<<" "<<p.y<<endl;
    cout<<e1.abs()<<endl;

    return 0;
}

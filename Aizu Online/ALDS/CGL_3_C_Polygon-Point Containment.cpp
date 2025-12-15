#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>


using namespace std;
static const double EPS = 1e-10; //__DBL_EPSILON__
enum turn {COUNTER_CLOCKWISE = 1, CLOCKWISE = -1 , ONLINE_BACK = 2, ONLINE_FRONT = -2, ON_SEGMENT = 0};
enum containment { OUT = 0, ON = 1, IN = 2};
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

    bool operator < (const Point p) { return !equals(x,p.x)? x < p.x : y < p.y; }
    bool operator == (const Point & p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
};
using Vector = Point;

double dot(Vector a, Vector b){ return a.x*b.x + a.y*b.y; }
double cross(Vector a, Vector b) { return a.x*b.y - b.x*a.y; }

struct Segment{
    Point p1, p2;
};
using Line = Segment;

class Circle{
public:
    Point c;
    double r;

    Circle(Point _c = Point(), double _r = 0): c(_c), r(_r){}
};

class Polygon{
public:
    vector<Point> points;

    Polygon(vector<Point> _points = vector<Point>()): points(_points){}
    void push_point(Point p) { points.push_back(p); }
    void pop_point() { points.pop_back(); }
    Point& operator[](int i) { return points[i]; }
};



bool is_orthogonal(Vector v1, Vector v2){ return equals(dot(v1,v2), 0.0);}
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) { return is_orthogonal(a1 - a2, b1 - b2); }
bool is_orthogonal(Segment s1, Segment s2) { return equals(dot(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0); }

bool is_parallel(Vector v1, Vector v2) { return equals(cross(v1,v2), 0.0); }
bool is_parallel(Point a1, Point a2, Point b1, Point b2) { return is_parallel(a1 - a2, b1 - b2); }
bool is_parallel(Segment s1, Segment s2) { return equals(cross(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0); }

//projection point of p on s
Point project(Segment s, Point p){
    Vector hypo = p - s.p1;
    Vector base = s.p2 - s.p1;
    Point pro = s.p1 + dot(hypo,base)/base.norm() * base;
    return pro; 
}

Point reflect(Segment s, Point p){
    Point pro = project(s, p);
    return p + (pro - p) * 2;
}

//the order of p0->p1 and p2
turn ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    else if(cross(a, b) < -EPS) return CLOCKWISE;
    else if(dot(a, b) < -EPS) return ONLINE_BACK;
    else if(a.norm() < b.norm()) return ONLINE_FRONT;
    else return ON_SEGMENT;
}

bool intersection(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersection(Segment s1, Segment s2){ return intersection(s1.p1, s1.p2, s2.p1, s2.p2); }

double distance(Point p1, Point p2) { return (p1-p2).abs(); }
double distance(Line l, Point p){ return fabs(cross(p - l.p1, l.p2 - l.p1)/(l.p2 - l.p1).abs()); }

double distance_s(Segment s, Point p ){
    if(dot(s.p2 - s.p1, p - s.p1) < 0) return (p - s.p1).abs();
    else if(dot(s.p1 - s.p2, p - s.p2) < 0) return (p - s.p2).abs();
    else return distance(s, p);
}
double distance(Segment s1, Segment s2){    
    if(intersection(s1, s2)) return 0;
    else return min(min(distance_s(s1, s2.p1), distance_s(s1, s2.p2)), min(distance_s(s2, s1.p1), distance_s(s2, s1.p2)));
}

Point cross_point(Segment s1, Segment s2){
    //if(!intersection(s1, s2)) return {NAN, NAN};
    Vector base = s2.p2 - s2.p1;
    double d1 = fabs(cross(base, s1.p1 - s2.p1)/base.abs());
    double d2 = fabs(cross(base, s1.p2 - s2.p1)/base.abs());
    double t = d1/ (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
};

pair<Point, Point> cross_points(Circle c, Line l){
    Point pr = project(l, c.c);
    Vector e = (l.p2 - l.p1)/(l.p1 - l.p2).abs();
    if(e.x > 0 || equals(e.x, 0.0) && e.y > 0) e = e * -1;
    double base = sqrt(c.r * c.r - (pr - c.c).norm());
    return make_pair(pr + e * base, pr - e * base);
}

//辐角
double arg(Vector v){ return atan2(v.y, v.x); }
//极坐标转向量
Vector polar(double r, double arg ){ return {r * cos(arg), r * sin(arg)}; }

pair<Point, Point> cross_points(Circle c1, Circle c2){
    double d = (c1.c - c2.c).abs();
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return {c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a)};
}

// check intersection times of y = p.y and the segment gi, gi+1 
// odd->containment, even->outside
containment contains(Polygon g, Point p){
    int n = g.points.size();
    bool is_in = false;    
    for (int i = 0; i < n; i++){
        Vector a = g[i] - p;
        Vector b = g[(i+1)%n] - p;
        if(fabs(cross(a, b)) < EPS && dot(a, b) < EPS) return ON;
        else{
            if(a.y > b.y) swap(a, b);
            if(a.y < EPS && b.y > EPS && cross(a, b) > EPS) is_in = !is_in;
        }
    }
    return is_in? IN : OUT;
}

int main(int argc, char const *argv[])
{
    Polygon g;
    double x, y;
    int n, q;
    cin>>n;
    for(int i = 0; i < n; i ++){
        cin>>x>>y;
        g.push_point({x, y});
    }
    cin>>q;
    for (int i = 0; i < q; i++){
        cin>>x>>y;
        cout<<contains(g, {x, y})<<endl;
    }
    return 0;
}






from math import atan2, sqrt, acos, cos, sin
from sys import float_info
from enum import Enum
from dataclasses import dataclass, field
from functools import singledispatch, cmp_to_key
import matplotlib.pyplot as plt
import matplotlib.patches as patches

EPS = float_info.epsilon
class Turn(Enum): 
    COUNTER_CLOCKWISE = 1
    CLOCKWISE = -1
    ONLINE_BACK = 2
    ONLINE_FRONT = -2
    ON_SEGMENT = 0
class Containment(Enum):
    OUT = 0
    ON = 1
    IN = 2
def equals(a, b) -> bool: return abs(a - b) < EPS

FIG, GEOAX = plt.subplots()

def add_geos(geos: iter):
    for g in geos:
        add_to_axis(g)

def add_to_axis(geo, x = 0, y = 0):
    if isinstance(geo, Point):
        if geo.is_vec:
            GEOAX.quiver([x], [y], [geo.x], [geo.y], scale_units='xy', scale=1, color='blue', width = 0.005)
        else:
            GEOAX.plot(geo.x, geo.y, marker='o', markersize=5, markerfacecolor='yellow', markeredgewidth=1, markeredgecolor='black', linestyle='None', label='points')
    elif isinstance(geo, Segment):
        p1, p2 = geo.p1, geo.p2
        if geo.is_line:
            GEOAX.axline((p1.x, p1.y), (p2.x, p2.y), label = 'Line', color='black')
        else:
            GEOAX.plot((p1.x, p2.x), (p1.y, p2.y), label = 'Segment', color='magenta')
    elif isinstance(geo, Circle):
        c, r = geo.c, geo.r
        circle = patches.Circle((c.x, c.y), radius = r, edgecolor='black', facecolor='orange', alpha=0.5)
        GEOAX.add_patch(circle)
    elif isinstance(geo, list):
        poly_points = [(p.x, p.y) for p in geo]
        poly = patches.Polygon(poly_points, closed=True, linewidth=1.5, edgecolor='black', facecolor='cyan', alpha=0.5)
        GEOAX.add_patch(poly)
    pass

def draw():
    # 自动调整轴的范围
    GEOAX.autoscale()
    # 设置xy横纵比
    GEOAX.axis('equal')
    # ax.set_aspect('equal', adjustable='box')
    # 启用网格
    GEOAX.grid(True)

    # 设置轴标签和标题
    GEOAX.set_xlabel('X-axis')
    GEOAX.set_ylabel('Y-axis')
    GEOAX.set_title('Geometries')
    # 显示图例
    # GEOAX.legend()

    # 显示图形
    plt.show()


# Point class
class Point:
    def __init__(self, x: float = 0, y :float = 0, is_vec: bool = False) -> None:
        self.x, self.y = x, y
        self.is_vec = is_vec
        pass
    
    def __add__(self, p: 'Point') -> 'Point':    return Point(self.x + p.x, self.y + p.y)
    def __sub__(self, p: 'Point') -> 'Point': return Point(self.x - p.x, self.y - p.y)
    def __mul__(self, a: float) -> 'Point': return Point(self.x * a, self.y * a)
    def __rmul__(self, a: float) -> 'Point': return self.__mul__(a)
    def __truediv__(self, a: float) -> 'Point': return Point(self.x / a, self.y / a)

    def abs(self) -> float: return sqrt(self.norm())
    def norm(self) -> float: return self.x ** 2 + self.y ** 2

    # default: compare x first
    def __lt__ (self, p: 'Point') -> bool: return self.x < p.x if not equals(self.x, p.x) else self.y < p.y
    def __eq__(self, p: 'Point') -> bool: return abs(self.x - p.x) < EPS and abs(self.y - p.y) < EPS
    
    def lt_y(self, p: 'Point') -> bool: return self.y < p.y if not equals(self.y,p.y) else self.x < p.x
    def dot(self, a: 'Vector') -> float: return self.x * a.x + self.y * a.y
    def cross(self, a: 'Vector') -> float: return self.x * a.y - a.x * self.y
    
    def __iter__(self):
        yield self.x
        yield self.y
    def __repr__(self) -> str:
        return f'(x={self.x}, y={self.y})'
Vector = Point

@dataclass
class Segment:
    p1: Point = field(default_factory=Point)
    p2: Point = field(default_factory=Point)
    is_line: bool = False

Line = Segment

@dataclass
class Circle:
    c: Point = field(default_factory=Point)
    r: float = 0

Polygon = list[Point]

def is_orthogonal(*args, **kwargs):
    if len(args) == 2:
        if isinstance(args[0], Vector):
            v1, v2 = args
            return equals(v1.dot(v2), 0.0)
        else:
            s1, s2 = args
            return equals((s1.p1 - s1.p2).dot(s2.p1 - s2.p2), 0.0)
    elif len(args == 4):
        a1, a2, b1, b2 = args
        return is_orthogonal(a1 - a2, b1 - b2)
    
def is_parallel(*args, **kwargs):
    if len(args) == 2:
        if isinstance(args[0], Vector):
            v1, v2 = args
            return equals(v1.cross(v2), 0.0)
        else:
            s1, s2 = args
            return equals((s1.p1 - s1.p2).cross(s2.p1 - s2.p2), 0.0)
    elif len(args == 4):
        a1, a2, b1, b2 = args
        return is_parallel(a1 - a2, b1 - b2)

# projection point of p on s
def project(s: Segment, p: Point) -> Point:
    hypo = p - s.p1
    base = s.p2 - s.p1
    pro = s.p1 + hypo.dot(base)/base.norm() * base
    return pro

def reflect(s: Segment, p: Point) -> Point:
    pro = project(s, p)
    return p + (pro - p) * 2

# he order of p0->p1 and p2
def ccw(p0: Point, p1: Point, p2: Point) -> Turn:
    a = p1 - p0
    b = p2 - p0
    if a.cross(b) > EPS: 
        return Turn.COUNTER_CLOCKWISE
    elif a.cross(b) < -EPS:
        return Turn.CLOCKWISE
    elif a.dot(b) < -EPS:
        return Turn.ONLINE_BACK
    elif(a.norm() < b.norm()):
        return Turn.ONLINE_FRONT
    else: 
        return Turn.ON_SEGMENT

# intersection of segments p1-p2 and p3-p4
def intersection(*args, **kwargs) -> bool:
    if len(args) == 4:
        p1, p2, p3, p4 = args
        return (ccw(p1, p2, p3).value * ccw(p1, p2, p4).value <= 0 and ccw(p3, p4, p1).value * ccw(p3, p4, p2).value <= 0)
    elif len(args) == 2:
        s1, s2 = args
        return intersection(s1.p1, s1.p2, s2.p1, s2.p2)

#Point, Point; Line, Point; Segment, Segment
def distance(*args, **kwargs) -> float:
    if isinstance(args[0], Point):
        p1, p2 = args
        return (p1-p2).abs()
    elif isinstance(args[0], Segment):
        if isinstance(args[1], Point):
            l, p = args
            return abs((p - l.p1).cross(l.p2 - l.p1)/(l.p2 - l.p1).abs())
        else:
            s1, s2 = args
            if(intersection(s1, s2)): 
                return 0
            else:
                return min(distance_s(s1, s2.p1), distance_s(s1, s2.p2), distance_s(s2, s1.p1), distance_s(s2, s1.p2))
        

def distance_s(s: Segment, p: Point) -> float:
    if (s.p2 - s.p1).dot(p - s.p1) < 0:
        return (p - s.p1).abs()
    elif (s.p1 - s.p2).dot(p - s.p2) < 0:
        return (p - s.p2).abs()
    else:
        return distance(s, p)
    
def cross_point(s1: Segment, s2: Segment) -> Point:
    # if(!intersection(s1, s2)) return {NAN, NAN}
    base = s2.p2 - s2.p1
    d1 = abs(base.cross(s1.p1 - s2.p1)/base.abs())
    d2 = abs(base.cross(s1.p2 - s2.p1)/base.abs())
    t = d1/ (d1 + d2)
    return s1.p1 + (s1.p2 - s1.p1) * t

# Circle, line or Circle, Circle
def cross_points(*args, **kwargs) -> tuple[Point, Point]:
    if isinstance(args[1], Line):
        c, l = args
        pr = project(l, c.c)
        e = (l.p2 - l.p1)/(l.p1 - l.p2).abs()
        if e.x > 0 or equals(e.x, 0.0) and e.y > 0: e = e * -1
        base = sqrt(c.r * c.r - (pr - c.c).norm())
        return (pr + e * base, pr - e * base)
    elif isinstance(args[1], Circle):
        c1, c2 = args
        d = (c1.c - c2.c).abs()
        a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d))
        t = arg(c2.c - c1.c)
        return (c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a))

# 辐角
def arg(v: Vector) -> float: return atan2(v.y, v.x)
# 极坐标转向量
def polar(r: float, arg: float) -> Vector: return Point(r * cos(arg), r * sin(arg))

# check intersection times of y = p.y and the segment gi, gi+1 
# odd->containment, even->outside the polygon
def contains(g: Polygon, p: Point) -> Containment:
    n = len(g)
    is_in = False    
    for i in range(n):
        a = g[i] - p
        b = g[(i+1)%n] - p
        if abs(a.cross(b)) < EPS and a.dot(b) < EPS: return Containment.ON
        else:
            if a.y > b.y:
                a, b = b, a
            if a.y < EPS and b.y > EPS and a.cross(b) > EPS:
                is_in = not is_in
    return Containment.IN if is_in else Containment.OUT


# build a convex hull which consists of a part of points from the input, and it contains all other points
def andrew_scan(points: list[Point]) -> Polygon:
    if(len(points) < 3):
        return Polygon(points)
    points.sort(key = lambda p: Point(p.y, p.x))
    n = len(points)
    up, low = [], []
    
    up.append(points[0])
    up.append(points[1])

    low.append(points[n-1])
    low.append(points[n-2])
    
    # build up
    for i in range(2, n):
        j = len(up)
        #                                                     != CLOCKWISE -> omit on_segment points
        while j >= 2 and ccw(up[j - 2], up[j - 1], points[i]) == Turn.COUNTER_CLOCKWISE:
            # print('popup')
            up.pop()
            j -= 1
        up.append(points[i])

    # build low
    for i in range(n - 3, -1, -1):
        j = len(low)
        while j >= 2 and ccw(low[j - 2], low[j - 1], points[i]) == Turn.COUNTER_CLOCKWISE:
            # print('a')
            low.pop()
            j -= 1
        low.append(points[i])

    # convert to counter-clockwise
    low.reverse()
    for i in range(len(up) - 2, 0, -1):
        low.append(up[i])
    return Polygon(low)

if __name__ == '__main__':
    x, y, r = map(int, input().split())
    c = Point(x, y)
    q = int(input())
    add_to_axis(Circle(c, r))
    for i in range(q):
        x1, y1, x2, y2 = map(int, input().split())
        p0 = Point(x1, y1)
        p1 = Point(x2, y2)
        add_to_axis(Line(p0, p1, True))
        cp1, cp2 = cross_points(Circle(c, r), Line(p0, p1));
        print(f'{cp1.x:.10f} {cp1.y:.10f} {cp2.x:.10f} {cp2.y:.10f}')
    draw()
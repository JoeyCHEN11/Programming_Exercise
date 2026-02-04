from __future__ import annotations
from sortedcontainers import SortedList, SortedSet
from dataclasses import dataclass

DOWN, LEFT, UP, RIGHT = 0, 1, 2, 3

@dataclass
class Seg_Point:
    tp: int
    x: int
    y: int
    other: Seg_Point = None
    def __lt__(self, other):
        # x 不参与排序
        return (self.y, self.tp) < (other.y, other.tp)

    
N = int(input())
points = []
for _ in range(N):
    x1, y1, x2, y2 = map(int, input().split())
    if x1 == x2:
        if y1 > y2: y1, y2 = y2, y1
        down, left = Seg_Point(DOWN, x1, y1), Seg_Point(UP, x2, y2)
        down.other = left
        left.other = down
        points.extend((down, left))
    else:
        if x1 > x2: x1, x2 = x2, x1
        left, right = Seg_Point(LEFT, x1, y1), Seg_Point(RIGHT, x2, y2)
        left.other = right
        right.other = left
        points.extend((left, right))

# x 用作查询
downs_x = SortedSet()

points.sort()

ans = 0
for p in points:
    if p.tp == DOWN:
        downs_x.add(p.x)
    elif p.tp == UP:
        downs_x.remove(p.other.x)
    elif p.tp == LEFT:
        left, right = p.x, p.other.x
        ans += downs_x.bisect_right(right) - downs_x.bisect_left(left) 

print(ans)

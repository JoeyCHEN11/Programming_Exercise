from collections import defaultdict
import bisect
w, h = map(int, input().split())
n = int(input())
cakes = [tuple(map(int, input().split())) for _ in range(n)]
A = int(input())
cutA = [0] + list(map(int, input().split()))
B = int(input())
cutB = [0] + list(map(int, input().split()))

# grid id: bottom left (x, y)
grids = defaultdict(int)

for p, q in cakes:
    x, y = bisect.bisect_left(cutA, p), bisect.bisect_left(cutB, q)
    grids[(x, y)] += 1

ansMin = 0 if (A + 1) * (B + 1) > len(grids) else min(grids.values())
ansMax = max(grids.values())
print(ansMin, ansMax)
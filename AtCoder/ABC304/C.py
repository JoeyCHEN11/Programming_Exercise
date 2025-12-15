from collections import deque
n, d = map(int, input().split())
points = [tuple(map(int, input().split())) for _ in range(n)]

d2 = d * d
infect = [False] * n
graph = [[] for _ in range(n)]

def sqd(x1, y1, x2, y2 ) -> int:
    return (x1 - x2)**2 + (y1 - y2)**2

for u in range(n - 1):
    ux, uy = points[u]
    for v in range(u + 1, n):
        vx, vy = points[v]
        if sqd(ux, uy, vx, vy) <= d2:
            graph[u].append(v)
            graph[v].append(u)

infect[0] = True
que = deque([0])
while que:
    u = que.popleft()
    for v in graph[u]:
        if not infect[v]:
            infect[v] = True
            que.append(v)
            
for inf in infect:
    print('Yes' if inf else 'No')
    
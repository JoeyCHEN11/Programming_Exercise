from collections import deque

n, m = map(int, input().split())
graph = [[] for _ in range(n)]

INF = float('inf')
pos = [(INF, INF) for _ in range(n)]

for i in range(m):
    a, b, x, y = map(int, input().split())
    graph[a - 1].append((b - 1, (x, y)))
    graph[b - 1].append((a - 1, (-x, -y)))

que = deque([0])
pos[0] = (0, 0)
while que:
    u = que.popleft()
    
    for v, (dx, dy) in graph[u]:
        if pos[v] == (INF, INF):
            pos[v] = (pos[u][0] + dx, pos[u][1] + dy)
            que.append(v)

for x, y in pos:
    print(x, y) if x != INF else print('undecidable')

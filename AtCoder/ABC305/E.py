from collections import deque
import heapq
n, m, k = map(int, input().split())
edges = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(m)]
guards = [tuple(map(int, input().split())) for _ in range(k)]

graph = [[] for _ in range(n)]
maxH = [-1] * n
for u, v in edges:
    graph[u].append(v)
    graph[v].append(u)
for p, h in guards:
    maxH[p - 1] = h
    
def bfs():
    pq = []
    for r in range(n):
        if maxH[r] != -1:
            pq.append((-maxH[r], r))
    heapq.heapify(pq)
    while pq:
        h, u = heapq.heappop(pq)
        h = -h
        if h < maxH[u]: continue
        
        for v in graph[u]:
            if maxH[v] < h - 1:
                maxH[v] = h - 1
                heapq.heappush(pq, (- (h - 1), v))
bfs()
ans = []
for u in range(n):
    if maxH[u] != -1:
        ans.append(u + 1)
        
print(len(ans))
for x in ans:
    print(x, end = ' ')
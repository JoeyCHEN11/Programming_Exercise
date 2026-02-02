import heapq

N = int(input())
G = [[] for _ in range(N)]

for u in range(N):
    info = list(map(int, input().split()))
    u, k = info[0], info[1]
    for i in range(2, 2 + 2 * k, 2):
        v, w = info[i], info[i + 1]
        G[u].append((w, v))
            
# for line in G:
#     print(line)

min_heap = []
min_dist = [float('inf')] * N
visited = [False] * N

heapq.heappush(min_heap, (0, 0))
min_dist[0] = 0
visited[0] = 0

while min_heap:
    min_d, u = heapq.heappop(min_heap)

    if visited[u]:
        continue
    visited[u] = True
    
    for w, v in G[u]:
        if not visited[v] and min_d + w < min_dist[v]:
            min_dist[v] = min_d + w
            heapq.heappush(min_heap, (min_d + w, v))

for u in range(N):
    print(u, min_dist[u])

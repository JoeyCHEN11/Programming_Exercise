import heapq
N = int(input())
G = [[] for _ in range(N)]

for u in range(N):
    for v, w in enumerate(map(int, input().split())):
        if w != -1:
            G[u].append((w, v))

dis_to_tree = [float('inf')] * N
visited = [False] * N

min_heap = []

heapq.heappush(min_heap,(0, 0))
dis_to_tree[0] = 0
mst_cost = 0

while min_heap:
    
    # pop from candidate
    min_w, u = heapq.heappop(min_heap)

    # if already in mst, skip
    if visited[u]:
        continue
    
    # add to mst
    visited[u] = True
    mst_cost += min_w
    
    for w, v in G[u]:
        if not visited[v] and w < dis_to_tree[v]:
            dis_to_tree[v] = w
            heapq.heappush(min_heap, (w, v))


print(mst_cost)
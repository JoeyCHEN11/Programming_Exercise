n, m = map(int, input().split())
graph = [[] for _ in range(n)]
indeg = [0] * n
for _ in range(m):
    u, v = map(int, input().split())
    graph[u - 1].append(v - 1)
    indeg[v - 1] += 1

stCnt, stIdx = 0, -1

for u, ind in enumerate(indeg):
    if ind == 0:
        stCnt += 1
        stIdx = u

if stCnt == 1:
    print(stIdx + 1)
else:
    print(-1)
    

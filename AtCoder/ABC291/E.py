from collections import deque
N, M = map(int, input().split())
edges = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]

in_deg = [0] * (N)
graph = [[] for _ in range(N)]
for u, v in edges:
    graph[u].append(v)
    in_deg[v] += 1

def topoSort(r: int) -> list[int]:
    que = deque([r])
    ans = [r]
            
    while que:
        u = que.popleft()
        
        uncertian = 0
        for v in graph[u]:
            in_deg[v] -= 1
            if in_deg[v] == 0:
                uncertian += 1
                ans.append(v)
                que.append(v)
        if uncertian > 1:
            return []
    return ans

def solve() -> list[int]:
    if in_deg.count(0) != 1 or [len(e) for e in graph].count(0) != 1:
        # no way
        return []
    ans = []
    r = in_deg.index(0)
    ans = topoSort(r)
    return ans if len(ans) == N else []
    
ans = solve()
per = [0] * N
print('Yes' if ans else 'No')
if ans:
    for i, x in enumerate(ans, 1):
        per[x] = i
    for p in per:
        print(p, end = ' ')
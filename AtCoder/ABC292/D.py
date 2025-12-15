from collections import deque
N, M = map(int, input().split())
edges = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
graph = [[] for _ in range(N)]
for u, v in edges:
    graph[u].append(v)
    graph[v].append(u)

comp_v = [0] * (N)
comp_e = [0] * (N)
visited = [False] * (N)
def bfs(r: int) -> tuple[int, int]:
    que = deque([r])
    visited[r] = True
    v_cnt, e_cnt = 1, 0
    while que:
        u = que.popleft()
        
        for v in graph[u]:
            e_cnt += 1
            if not visited[v]:
                visited[v] = True
                v_cnt += 1
                que.append(v)
    return v_cnt, e_cnt // 2

for i in range(N):
    if not visited[i]:
        comp_v[i], comp_e[i] = bfs(i)
print('Yes' if comp_e == comp_v else 'No')

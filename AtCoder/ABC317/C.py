n, m = map(int, input().split())
graph = [[] for _ in range(n)]
visited = [False] * n
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a - 1].append((b - 1, c))
    graph[b - 1].append((a - 1, c))


def dfs(u: int) -> int:
    visited[u] = True
    
    ans = 0
    for v, w in graph[u]:
        if not visited[v]:
            ans = max(ans, w + dfs(v))
    visited[u] = False
    return ans
    
ans = 0
for r in range(n):
    visited = [False] * n
    ans = max(ans, dfs(r))
print(ans)
    

from collections import deque
n1, n2, m = map(int, input().split())
graph = [[] for _ in range(n1 + n2)]
# visited = [False] * (n1 + n2)
distance = [-1] * (n1 + n2)
for _ in range(m):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)
    
def bfs(r: int) -> int:
    ans = -1
    distance[r] = 0
    que = deque([r])
    # visited[r] = True
    while que:
        u = que.popleft()
        ans = distance[u]
        
        for v in graph[u]:
            if distance[v] == -1:
                # visited[v] = True
                distance[v] = distance[u] + 1
                que.append(v)
    return ans

print(bfs(0) + bfs(n1 + n2 - 1) + 1)
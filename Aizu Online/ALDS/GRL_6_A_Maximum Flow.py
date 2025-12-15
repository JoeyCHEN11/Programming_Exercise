from collections import deque

V, E = map(int, input().split())
graph = [[0] * V for _ in range(V)]
residual = [[0] * V for _ in range(V)]

for _ in range(E):
    u, v, c = map(int, input().split())
    graph[u][v] = c
    residual[u][v] = c

# find augmenting path
def bfs(r, t):
    visited = [False] * V
    visited[r] = True
    parent = [-1] * V
    que = deque([r])
    while que:
        u = que.popleft()

        for v, c in enumerate(residual[u]):
            if not visited[v] and c != 0:
                visited[v] = True
                parent[v] = u
                que.append(v)

    bot, ans = float('inf'), [t]
    i = t
    while parent[i] != -1:
        ans.append(parent[i])
        bot = min(residual[parent[i]][i], bot)
        i = parent[i]
    ans.reverse()
    return (ans, bot)

while True:
    path, bot = bfs(0, V - 1)
    # no augmenting path
    if len(path) < 2: break

    for i in range(len(path) - 1):
        u, v = path[i], path[i + 1]
        # fill residual
        residual[u][v] -= bot
        # build back edge
        residual[v][u] += bot

ans = 0
for v, c in enumerate(graph[0]):
    ans += graph[0][v] - residual[0][v]
print(ans)
    
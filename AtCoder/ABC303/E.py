from collections import deque
n = int(input())
graph = [[] for _ in range(n)]
degree = [0] * n
for _ in range(n - 1):
    u, v = map(int, input().split())
    graph[u - 1].append(v - 1)
    graph[v - 1].append(u - 1)
    degree[v - 1] += 1
    degree[u - 1] += 1
    
ans = []
distance = [-1] * n
que = deque()
for i in range(n):
    if degree[i] == 1:
        r = graph[i][0]
        que.append(r)
        distance[r] = 0
        break
    
while que:
    u = que.popleft()
    if distance[u] % 3 == 0:
        ans.append(degree[u])
    
    for v in graph[u]:
        if distance[v] == -1:
            que.append(v)
            distance[v] = distance[u] + 1

for x in sorted(ans):
    print(x, end = ' ')
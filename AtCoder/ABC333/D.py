from collections import deque
n = int(input())
graph = [[] for _ in range(n)]
visited = [False] * n

for _ in range(n - 1):
    u, v = map(lambda x: int(x) - 1, input().split())
    graph[u].append(v)
    graph[v].append(u)
    
def bfsCnt(r: int) -> int:
    cnt = 1
    visited[r] = True
    que = deque([r])
    
    while que:
        u = que.popleft()
        for v in graph[u]:
            if not visited[v]:
                cnt += 1
                que.append(v)
                visited[v] = True
    return cnt

visited[0] = True
ans = 0
maxChildren = -1
for r in graph[0]:
    cnt = bfsCnt(r)
    # print('Cnt:', cnt)
    ans += cnt
    maxChildren = max(maxChildren, cnt)
    
print(ans - maxChildren + 1)
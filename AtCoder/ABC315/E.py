from collections import deque
n = int(input())
graph = [[] for _ in range(n)]
# visited = [False] * n
for u in range(n):
    info = list(map(int, input().split()))
    cnt, pres = info[0], info[1:]
    for v in pres:
        graph[u].append(v - 1)
        
def topoSort(graph: list[list[int]]) -> list[int]:
    n = len(graph)
    inDegree = [0] * n
    for u in range(n):
        for v in graph[u]:
            inDegree[v] += 1
    
    que = deque()
    ans = []
    for i in range(n):
        if inDegree[i] == 0:
            que.append(i)
            ans.append(i)
            
    while que:
        u = que.popleft()
        
        for v in graph[u]:
            inDegree[v] -= 1
            if inDegree[v] == 0:
                ans.append(v)
                que.append(v)
    return ans

request = [False] * n

def bfs(r: int):
    request[r] = True
    que = deque([r])
    while que:
        u = que.popleft()
        
        for v in graph[u]:
            if not request[v]:
                request[v] = True
                que.append(v)

bfs(0)
rtopo = reversed(topoSort(graph))
ans = []
for x in rtopo:
    if request[x]:
        ans.append(x)

for x in ans:
    if x == 0: break
    print(x + 1, end= ' ')
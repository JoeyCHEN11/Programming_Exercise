from collections import deque


n, m = map(int, input().split())
edges = zip(list(map(int, input().split())), list(map(int, input().split())))
graph = [[] for _ in range(n)]

colors = [0] * n

for (u, v) in edges:
    graph[u - 1].append(v - 1)
    graph[v - 1].append(u - 1)

def dfsIsBi(u: int, color: int) -> bool:
    colors[u] = color # Gray
    
    for v in graph[u]:
        if colors[v] == color:
            return False
        if colors[v] == 0 and not dfsIsBi(v, -color):
            return False
    return True # Black

def bfsIsBi(r: int) -> bool:
    que = deque([r])
    colors[r] = 1
    
    while que:
        u = que.popleft()
        
        for v in graph[u]:
            if colors[v] == colors[u]:
                return False
            elif colors[v] == 0:
                colors[v] = -colors[u]
                que.append(v)
            
    return True

isBi = True
for r, color in enumerate(colors):
    if color == 0:
        isBi &= bfsIsBi(r)

print('Yes' if isBi else 'No')

    
from collections import deque
n, m = map(int, input().split())
s = list(input())
t = input()

visited = [False] * (n - m + 1)

def checkAndSet(idx: int) -> bool:
    ok = True
    for i in range(m):
        ok = ok & (s[idx + i ] == t[i] or s[idx + i] == '#')
    if ok:
        for i in range(m):
            s[idx + i] = '#'
    return ok

def bfs(r: int):
    que = deque([r])
    visited[r] = True
    
    while que:
        u = que.popleft()
        for v in range(max(0, u - m + 1), min(u + m, n - m + 1)):
            if not visited[v] and checkAndSet(v):
                visited[v] = True
                que.append(v)

for i in range(n - m + 1):
    if checkAndSet(i):
        bfs(i)
        
print('Yes' if all(visited) else 'No')


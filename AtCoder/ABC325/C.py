from collections import deque
from itertools import permutations
h, w = map(int, input().split())
grid = [input() for _ in range(h)]
visited = [[False] * w for _ in range(h)]
dicts = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def availablePos(i: int, j: int) -> bool:
    return 0 <= i < h and 0 <= j < w

def bfs(ri: int, rj: int):
    visited[ri][rj] = True
    que = deque([(ri, rj)])
    
    while que:
        ui, uj = que.popleft()
        
        for dx, dy in dicts:
            vi, vj = ui + dx, uj + dy
            if availablePos(vi, vj) and grid[vi][vj] == '#' and not visited[vi][vj]:
                visited[vi][vj] = True
                que.append((vi, vj))

cnt = 0
for i in range(h):
    for j in range(w):
        if grid[i][j] == '#' and not visited[i][j]:
            cnt += 1
            bfs(i, j)
            
print(cnt)
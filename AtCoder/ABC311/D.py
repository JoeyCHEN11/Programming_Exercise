from collections import deque
n, m = map(int, input().split())
grid = [input() for _ in range(n)]
graph = [[[] for _ in range(m)] for _ in range(n)]
visited = [[False] * m for _ in range(n)]
directs = ((0, -1), (-1, 0), (0, 1), (1, 0))
def available(i: int, j: int) -> bool:
    return 0 <= i < n and 0 <= j < m

# for i in range(n):
#     for j in range(m):

def bfs(ri: int, rj: int) -> int:
    que = deque([(ri, rj)])
    visited[ri][rj] = True
    
    while que:
        ui, uj = que.popleft()

        for dx, dy in directs:
            vi, vj = ui, uj
            while grid[vi + dx][vj + dy] != '#':
                visited[vi][vj] = True
                vi, vj = vi + dx, vj + dy
            
            if not visited[vi][vj]:
                visited[vi][vj] = True
                que.append((vi, vj))
    # for r in visited:
    #     print(r)
    return(sum(sum(r) for r in visited))
          
print(bfs(1, 1))
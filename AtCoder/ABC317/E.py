from collections import deque
h, w = map(int, input().split())
grid = [list(input()) for _ in range(h)]
sightDir = {'<': (0, -1), '>': (0, 1), 'v':(1, 0), '^': (-1, 0), '#': (0, 0)}
obscale = {'<', '>', 'v', '^', '#', '!'}
dir = ((-1, 0), (0, 1), (1, 0), (0, -1))
distances = [[-1] * w for _ in range(h)]
si, sj, gi, gj = -1, -1, -1, -1
def available(i: int, j: int) -> bool:
    return 0 <= i < h and 0 <= j < w

for i in range(h):
    for j in range(w):
        if grid[i][j] in sightDir:
            di, dj = sightDir[grid[i][j]]
            vi, vj = i + di, j + dj
            while available(vi, vj) and grid[vi][vj] not in sightDir:
                grid[vi][vj] = '!'
                vi, vj = vi + di, vj + dj
        if grid[i][j] == 'S':
            si, sj = i, j
        if grid[i][j] == 'G':
            gi, gj = i, j

# for row in grid:
#     print(row)

def bfs(ri: int, rj: int) -> int:
    que = deque([(ri, rj)])
    distances[ri][rj] = 0
    while que:
        ui, uj = que.popleft()
        
        if ui == gi and uj == gj:
            return distances[ui][uj]
        
        for dx, dy in dir:
            vi, vj = ui + dx, uj + dy
            if available(vi, vj) and grid[vi][vj] not in obscale and distances[vi][vj] == -1:
                distances[vi][vj] = distances[ui][uj] + 1
                que.append((vi, vj))
    return distances[gi][gj]
    
print(bfs(si, sj))
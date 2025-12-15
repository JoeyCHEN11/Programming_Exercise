from collections import deque, defaultdict
h, w = map(int, input().split())
grid = [input() for _ in range(h)]
nextChr = defaultdict(str)
nextChr.update({'s': 'n', 'n': 'u', 'u': 'k', 'k': 'e', 'e': 's'})
# print(nextChr)
direct = ((0, 1), (1, 0), (0, -1), (-1, 0))
visited = [[False] * w for _ in range(h)]

def available(i, j) -> bool:
    return 0 <= i < h and 0 <= j < w
def bfs(ri: int, rj: int, ti: int, tj: int) -> bool:
    que = deque([(ri, rj)])
    visited[ri][rj] = True
    while que:
        ui, uj = que.popleft()
        uc = grid[ui][uj]
        
        for dx, dy in direct:
            vi, vj = ui + dx, uj + dy
            if available(vi, vj) and nextChr[uc] == grid[vi][vj] and not visited[vi][vj]:
                que.append((vi, vj))
                visited[vi][vj] = True
    return visited[ti][tj]

print('Yes' if bfs(0,0, h - 1, w - 1) else 'No')
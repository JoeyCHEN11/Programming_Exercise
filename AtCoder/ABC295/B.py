from collections import deque
M, N = map(int, input().split())
grid = [list(input()) for _ in range(M)]
power = [[-1] * N for _ in range(M)]
direct = ((0, 1), (1, 0), (0, -1), (-1, 0))
def available(i, j) -> bool:
    return 0 <= i < M and 0 <= j < N

que = deque()
for i in range(M):
    for j in range(N):
        if grid[i][j].isdigit():
            que.append((i, j))
            power[i][j] = int(grid[i][j])
            grid[i][j] = '.'
            
while que:
    ui, uj = que.popleft()
    up = power[ui][uj]
    
    if up <= 0: continue
    
    for dx, dy in direct:
        vi, vj = ui + dx, uj + dy
        if available(vi, vj) and power[vi][vj] < up - 1:
            grid[vi][vj] = '.'
            que.append((vi, vj))
            power[vi][vj] = up - 1

for row in grid:
    print(''.join(row))
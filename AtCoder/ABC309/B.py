n = int(input())
grid = [list(input()) for _ in range(n)]

tmp = grid[0][0]

for i in range(1, n):
    grid[i - 1][0] = grid[i][0]
    
for i in range(1, n):
    grid[-1][i - 1] = grid[-1][i]
    
for i in range(n - 2, -1, -1):
    grid[i + 1][-1] = grid[i][-1]
    
for i in range(n - 2, -1, -1):
    grid[0][i + 1] = grid[0][i]
    
grid[0][1] = tmp

for row in grid:
    print(''.join(row))

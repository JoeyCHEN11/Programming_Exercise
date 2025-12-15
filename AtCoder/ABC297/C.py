H, W = map(int, input().split())
grid = [list(input()) for _ in range(H)]

for i in range(H):
    for j in range(W - 1):
        if (grid[i][j], grid[i][j + 1]) == ('T', 'T'):
            grid[i][j], grid[i][j + 1] = 'P', 'C'
            
for r in grid:
    print(''.join(r))
    
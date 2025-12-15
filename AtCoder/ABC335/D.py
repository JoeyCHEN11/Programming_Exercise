n = int(input())
grid = [[0] * n for _ in range(n)]

grid [n // 2][n // 2] = 'T'

directs = [(0, 1), (1, 0), (0, -1), (-1, 0)]


i, j = 0, 0
part = 1
for offset in range(1, n // 2 + 1):
    while j < n - offset:
        grid[i][j] = part
        part += 1
        j += 1
    while i < n - offset:
        grid[i][j] = part
        part += 1
        i += 1
    while j >= offset:
        grid[i][j] = part
        part += 1
        j -= 1
    while i >= offset:
        grid[i][j] = part
        part += 1
        i -= 1
    i, j = i + 1, j + 1
        
for line in grid:
    for ans in line:
        print(ans, end=' ')
    print()
n, m = map(int, input().split())
grid = [input() for _ in range(n)]

def isTak(si: int, sj: int) -> bool:
    for i in range(si, si + 3):
        for j in range(sj, sj + 3):
            if grid[i][j] != '#':
                return False
    i = si + 3
    for j in range(sj, sj + 4):
        if grid[i][j] != '.':
            return False
    
    j = sj + 3
    for i in range(si, si + 4):
        if grid[i][j] != '.':
            return False
    
    for i in range(si + 6, si + 9):
        for j in range(sj + 6, sj + 9):
            if grid[i][j] != '#':
                return False
    
    i = si + 5
    for j in range(sj + 5, sj + 9):
        if grid[i][j] != '.':
            return False

    j = sj + 5
    for i in range(si + 5, si + 9):
        if grid[i][j] != '.':
            return False

    
    return True
    
    
ans = []
for i in range(n - 9 + 1):
    for j in range(m - 9 + 1):
        # print('check', i, j)
        if isTak(i, j):
            ans.append((i + 1, j + 1))
    
for i, j in ans:
    print(i, j)
    
# from itertools import product
h, w = map(int, input().split())
grid = [input() for _ in range(h)]
cross = [0] * (min(h, w) + 1)
direct = ((1, 1), (1, -1), (-1, 1), (-1, -1))
def get(i, j) -> str:
    if 0 <= i < h and 0 <= j < w:
        return grid[i][j]
    else:
        return '.'
def corner_check(i, j, d):
    # print('Check:', i, j, d)
    for dx, dy in direct:
        if get(i + dx * d, j + dy * d) == '.':
            return False
    return True
    
def find_cross(ci, cj) -> int:
    i, j = ci, cj
    d = 1
    while corner_check(i, j, d):
        d += 1
    # print('cross:', i, j,)
    return d - 1

for i in range(h):
    for j in range(w):
        if grid[i][j] == '#':
            cross[find_cross(i, j)] += 1
        
for cnt in cross[1:]:
    print(cnt, end=' ')
        
    
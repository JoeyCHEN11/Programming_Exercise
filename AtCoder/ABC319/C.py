import math
from itertools import product, permutations
grid = []

for _ in range(3):
    grid.extend(list(map(int, input().split())))

linesIdx = [ (0, 1, 2), (3, 4, 5), (6, 7, 8), # rows
            (0, 3, 6), (1, 4, 7), (2, 5, 8), # cols
            (0, 4, 8), (2, 4, 6) # diagonals
            ] 
not_disap, cnt = 0, 0
# enumerate the orders of squares
for order in permutations(range(9)):
    # idx in grid, the order in permutation
    cnt += 1
    disp = False
    for i, j, k in linesIdx:
        if grid[i] == grid[j] and order[i] < order[k] and order[j] < order[k]:
            disp = True
        if grid[i] == grid[k] and order[i] < order[j] and order[k] < order[j]:
            disp = True
        if grid[j] == grid[k] and order[j] < order[i] and order[k] < order[i]:
            disp = True
    
    if not disp:
        not_disap += 1
    
print(f'{not_disap/cnt:.9f}')
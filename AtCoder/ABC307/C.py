from copy import deepcopy
ha, wa = map(int, input().split())
gridA = [input() for _ in range(ha)]
hb, wb = map(int, input().split())
gridB = [input() for _ in range(hb)]
hx, wx = map(int, input().split())
gridX = [input() for _ in range(hx)]

def findBound(grid) -> tuple:
    left, right, up, down = float('inf'), -1, float('inf'), -1
    h, w = len(grid), len(grid[0])
    for i in range(h):
        for j in range(w):
            if grid[i][j] == '#':
                right = max(right, j + 1)
                down = max(down, i + 1)
                
                left = min(left, j)
                up = min(up, i)
    return left, right, up, down

def matchX(sheet: list[list[str]]) -> bool:
    for i in range(hx):
        for j in range(wx):
            if sheet[i][j] != gridX[i][j]:
                return False
    return True

def fill(sheet, ri, rj, grid, left, up, down, right):
    for i in range(up, down):
        for j in range(left, right):
            if grid[i][j] == '#':
                sheet[ri + (i - up)][rj + (j - left)] = '#' 

def tryCut() -> bool:
    aleft, aright, aup, adown = findBound(gridA)
    bleft, bright, bup, bdown = findBound(gridB)
    cha, cwa = adown - aup, aright - aleft
    chb, cwb = bdown - bup, bright - bleft
    for ai in range(hx - cha + 1):
        for aj in range(wx - cwa + 1):
            sheetA = [['.'] * wx for _ in range(hx)]
            fill(sheetA, ai, aj, gridA, aleft, aup, adown, aright)
            for bi in range(hx - chb + 1):
                for bj in range(wx - cwb + 1):
                    sheetB = deepcopy(sheetA)
                    fill(sheetB, bi, bj, gridB, bleft, bup, bdown, bright)
                    if matchX(sheetB):
                        return True
    return False

print('Yes' if tryCut() else 'No')
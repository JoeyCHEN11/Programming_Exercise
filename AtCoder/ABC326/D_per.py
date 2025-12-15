from itertools import permutations
n = int(input())
rowLeft, colUp = input(), input()
grid = [['.' for _ in range(n)] for _ in range(n)]
alphabet = 'ABC'
rows = [{'A': False, 'B': False, 'C': False} for _ in range(n)]
cols = [{'A': False, 'B': False, 'C': False} for _ in range(n)]
cUpPos = [n] * n

def validLine(r: int, cpos: tuple[int]) -> bool:
    leftPos = cpos.index(min(cpos))
    res = alphabet[leftPos] == rowLeft[r]

    for c, ch in zip(cpos, alphabet):
        res = res and rows[r][ch] == False and cols[c][ch] == False

        if r <= cUpPos[c]:
            res = res & (colUp[c] == ch)
    return res

def setLine(r: int, cpos: tuple[int]):
    
    for c, ch in zip(cpos, alphabet):
        grid[r][c] = ch
        
        rows[r][ch] = True
        cols[c][ch] = True

        if r < cUpPos[c]:
            cUpPos[c] = r
            
def removeLine(r: int, cpos: tuple[int]):
    # print('before remove:')
    # print(grid)
    for c, ch in zip(cpos, alphabet):
        # print('remove', r, c)
        ch = grid[r][c]
        
        rows[r][ch] = False
        cols[c][ch] = False

        if r == cUpPos[c]:
            cUpPos[c] = n
        # print(grid[r][c])
        grid[r][c] = '.'
        # print(grid[r][c])

def fillPuzzle(r: int) -> bool:
    if r >= n:
        return True
    
    for cpos in permutations(range(n), 3):
        # print(cpos)
        if validLine(r, cpos):
            # print('row:', r)
            # print('set',cpos)
            setLine(r, cpos)
            if fillPuzzle(r + 1):
                return True
            # print('row:', r)
            # print('remove', cpos)
            removeLine(r, cpos)
            # print(grid)
    return False        
    
if fillPuzzle(0):
    print('Yes')
    for line in grid:
        print(''.join(line))
else:
    print('No')
# print(sum(rows[0].values()))
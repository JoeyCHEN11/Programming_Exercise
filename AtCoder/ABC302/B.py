h, w = map(int, input().split())
grid = [input() for _ in range(h)]
direct = ((0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (-1, -1), (1, -1), (-1, 1))
snuke = 'snuke'
def available(i, j):
    return 0 <= i < h and 0 <= j < w
def findSnuke(ri: int, rj: int, d: tuple[int, int]) -> list[tuple]:
    i, j = ri, rj
    dx, dy = d
    ans = [(i + 1, j + 1)]
    if grid[ri][rj] != snuke[0]:
        return []
    # print('direct:', dx, dy)
    for k in range(1, 5):
        i, j = i + dx, j + dy
        ans.append((i + 1, j + 1))
        if not available(i, j) or grid[i][j] != snuke[k]:
            return []
    return ans

def getSnuke():
    for i in range(h):
        for j in range(w):
            for d in direct:
                ans = findSnuke(i, j, d)
                if ans:
                    return ans
    return []

ans = getSnuke()
for i, j in ans:
    print(i, j)    
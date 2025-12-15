N, Q = map(int, input().split())
grid = [list(map(lambda x : 0 if x == 'W' else 1, input())) for _ in range(N)]
queries = [tuple(map(int, input().split())) for _ in range(Q)]

preCal = [[0] * (N + 1) for _ in range(N + 1)]
for i in range(1, N + 1):
    for j in range(1, N + 1):
        preCal[i][j] = grid[i - 1][j - 1] + preCal[i - 1][j] + preCal[i][j - 1] - preCal[i - 1][j - 1]

def getArea(h: int, w: int) -> int:
    if h <= N and w <= N: return preCal[h][w] 
    hCnt, wCnt = h // N, w // N
    hMod, wMod = h % N, w % N
    ans = 0
    ans += getArea(N, N) * hCnt * wCnt
    ans += getArea(hMod, N) * wCnt
    ans += getArea(N, wMod) * hCnt
    ans += getArea(hMod, wMod)
    return ans

for a, b, c, d in queries:
    ans = getArea(c + 1, d + 1) - getArea(c + 1, b) - getArea(a, d + 1) + getArea(a, b)
    print(ans)
# getArea(5, 6)
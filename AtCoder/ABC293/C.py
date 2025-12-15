from itertools import combinations
H, W = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(H)]

steps = [(0, 1)] * W + [(1, 0)] * H
ans = 0
for downs in combinations(range(H + W - 2), H - 1):
    # 0: right, 1: down
    paths = [(0, 1)] * (H + W - 2)
    for d in downs:
        paths[d] = (1, 0)
    i, j = 0, 0
    check = set([grid[i][j]])
    ok = True
    for dx, dy in paths:
        i, j = i + dx, j + dy
        if grid[i][j] in check:
            ok = False
            break
        else:
            check.add(grid[i][j])
    if ok: ans += 1
print(ans)
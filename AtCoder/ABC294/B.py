H, W = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(H)]
ans = [['.'] * W for _ in range(H)]
for i in range(H):
    for j in range(W):
        if grid[i][j]:
            ans[i][j] = chr(ord('A') - 1 + grid[i][j])
for r in ans:
    print(''.join(r))
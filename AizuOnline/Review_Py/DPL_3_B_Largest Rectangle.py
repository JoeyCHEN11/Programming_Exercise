H, W = map(int, input().split())

tiles = [[1] * W]

for i in range(H):
    tiles.append([1] + list(map(int, input().split())))

ans = 0
dp = [[0] * (W + 1) for _ in range(H + 1)]

for i in range(1, H + 1):
    for j in range(1, W + 1):
        if tiles[i][j]: continue
        right = dp[i][j - 1]
        up = dp[i - 1][j] 
        upright = dp[i - 1][j - 1] 
        dp[i][j] = min(right, up, upright) + 1
        ans = max(ans, dp[i][j])
        
print(ans ** 2)
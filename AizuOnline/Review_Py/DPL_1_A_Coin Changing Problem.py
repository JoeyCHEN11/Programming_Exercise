N, M = map(int, input().split())

coins = list(map(int, input().split()))

# dp = [[float('inf')] * (N + 1) for _ in range(M + 1)]
# for i in range(1, M + 1):
#     dp[i][0] = 0

# for i in range(1, M + 1):
#     for j in range(1, N + 1):
#         val = dp[i][j - coins[i]] if j - coins[i] >= 0 else float('inf')
#         dp[i][j] = min(dp[i - 1][j], val + 1)
        
# print(dp[M][N])


dp_1d = [0] + [float('inf')] * (N)
for i in range(M):
    for j in range(coins[i], N + 1):
        dp_1d[j] = min(dp_1d[j - coins[i]] + 1, dp_1d[j])

print(dp_1d[N])

import bisect
N, K = map(int, input().split())
takoyaki = list(map(int, input().split()))

dp = [[0] * (K + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    for k in range(1, K + 1):
        j1 = bisect.bisect_right(dp[i - 1], dp[i][k - 1], 0, k)
        dp[i][k] = dp[i - 1][j1] if dp[i - 1][j1] > dp[i][k - 1] else float('inf')
        
        j2 = bisect.bisect_right(dp[i], dp[i][k - 1] - takoyaki[i - 1], 0, k)
        dp[i][k] = min(dp[i][k], dp[i][j2] + takoyaki[i - 1])
        
# for r in dp:
#     print(r)
print(dp[N][K])

# dp2D = [[0] * (K + 1) for _ in range(2)]
# pre, cur = 0, 1
# for i in range(1, N + 1):
#     for k in range(1, K + 1):

#         j1 = bisect.bisect_right(dp2D[0], dp2D[1][k - 1], 0, k)
#         dp2D[1][k] = dp2D[0][j1] if dp2D[0][j1] > dp2D[1][k - 1] else float('inf')
        
#         j2 = bisect.bisect_right(dp2D[1], dp2D[1][k - 1] - takoyaki[i - 1], 0, k)
#         dp2D[1][k] = min(dp2D[1][k], dp2D[1][j2] + takoyaki[i - 1])
        
#     dp2D[0], dp2D[1] = dp2D[1], dp2D[0]
        
# print(dp2D[0][K])
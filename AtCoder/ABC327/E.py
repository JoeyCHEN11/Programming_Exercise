import math
n = int(input())
scores = list(map(int, input().split()))
dp = [[0] * (n + 1) for _ in range(n + 1)]
# dp1D = [0] * (n + 1)

# for i in range(1, n + 1):
#     dp[i][i] = dp[i - 1][i - 1] * 0.9 + scores[i - 1]
    
for i in range(1, n + 1):
    for j in range(i, 0, -1):
        dp[i][j] = max(dp[i - 1][j], 0.9 * dp[i - 1][j - 1] + scores[i - 1])
        # dp1D[j] = max(dp1D[j], 0.9 * dp1D[j - 1] + scores[i - 1])
        
w, ans = 0, float('-inf')

for k, sc in enumerate(dp[n][1:], 1):
    w = w * 0.9 + 1
    ans = max(ans, sc/w - 1200/(math.sqrt(k)))

# for k, sc in enumerate(dp1D[1:], 1):
#     w = w * 0.9 + 1
#     ans = max(ans, sc/w - 1200/(math.sqrt(k)))
        
print(f'{ans:.7f}')

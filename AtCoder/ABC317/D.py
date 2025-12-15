n = int(input())
t_a_z = [tuple(map(int, input().split())) for _ in range(n)]

winVote = sum(v[2] for v in t_a_z) // 2 + 1
switches = [max((v[1] - v[0] + 1) // 2, 0) for v in t_a_z]
# print(switches)
dp = [[float('inf')] * (winVote + 1) for _ in range(n + 1)]

dp[0][0] = 0
for i in range(1, n + 1):
    for j in range(0, winVote + 1):
        z = t_a_z[i - 1][2]
        dp[i][j] = min(dp[i - 1][j], switches[i - 1] + dp[i - 1][max(j - z, 0)])
            
print(dp[n][winVote])
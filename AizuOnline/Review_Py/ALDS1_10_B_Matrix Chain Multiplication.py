N = int(input())
matrics = [(int(input().split()[0])) for _ in range(N - 1)]
matrics += list(map(int, input().split()))
# print(matrics)

dp = [[float('inf') if i != j else 0 for i in range(N + 1)] for j in range(N + 1)]

for l in range(2, N + 1):
    for i in range(1, N - l + 2):
        j = i + l - 1
        for k in range(i, j):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrics[i - 1] * matrics[k] * matrics[j])

print(dp[1][N])

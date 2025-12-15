n = int(input())
weights = [list(map(int, input().split())) for _ in range(n - 1)]

graph = [[0] * n for _ in range(n)]
for i in range(n - 1):
    for j in range(i + 1, n):
        graph[i][j] = weights[i][j - i - 1]
        graph[j][i] = weights[i][j - i - 1]
        
# print(graph)
dp = [0] * (1 << n)
dp[0] = 0
for b in range(1, 1 << n):
    for u in range(n):
        if b >> u & 1:
            for v in range(u, n):
                if b >> v & 1:
                    preB = (1 << v | 1 << u) ^ b
                    dp[b] = max(dp[b], dp[preB] + graph[u][v])
# print(dp)
print(dp[(1<<n) - 1])

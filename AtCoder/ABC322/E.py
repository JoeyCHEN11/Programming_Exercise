from itertools import product
n, k, p = map(int, input().split())
costs, plans = [0 for _ in range(n)], [[] for _ in range(n)]

for i in range(n):
    ca = list(map(int, input().split()))
    costs[i] = ca[0]
    plans[i] = ca[1:]
    
dp = [{} for _ in range(n + 1)]

for i in range(n + 1):
    for tp in product(range(p + 1), repeat = k):
        dp[i][tp] = float('inf')
        
dp[0][(0,) * k] = 0
for i in range(1, n + 1):
    for tp in product(range(p + 1), repeat = k):
        prevP = list(tp)
        for j in range(k):
            prevP[j] = max(0, prevP[j] - plans[i - 1][j])
        dp[i][tp] = min(costs[i - 1] + dp[i - 1][tuple(prevP)], dp[i - 1][tp])

print(dp[n][(p,) * k] if dp[n][(p,) * k] != float('inf') else -1)
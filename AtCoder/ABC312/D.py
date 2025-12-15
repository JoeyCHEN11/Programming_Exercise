s = input()
n = len(s)
dp = [[0] * (n + 1) for _ in range(n + 1)]
MOD = 998244353

dp[0][0] = 1

for i in range(1, n + 1):
    for j in range(n + 1):
        if s[i - 1] == '(' and j > 0:
            dp[i][j] = dp[i - 1][j - 1]
        elif s[i - 1] == ')' and j < n:
            dp[i][j] = dp[i - 1][j + 1]
        elif s[i - 1] == '?':
            if j > 0: # let ? be '('
                dp[i][j] += dp[i - 1][j - 1]
            if j < n: # let ? be ')'
                dp[i][j] += dp[i - 1][j + 1]
        dp[i][j] %= MOD

# for r in dp:
#     print(r)
print(dp[n][0])

                
            

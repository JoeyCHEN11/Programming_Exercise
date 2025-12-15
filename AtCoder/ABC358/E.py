K = int(input())
C = list(map(int, input().split()))
MOD = 998244353
dp = [[0] * (K + 1) for _ in range(27)]

facs = [0] * (K + 1)
invs = [0] * (K + 1)
facs[0], invs[0] = 1, 1
for k in range(1, K + 1):
    facs[k] = (facs[k - 1] * k) % MOD
    invs[k] = pow(facs[k], -1, MOD)

def combMod(n: int, k: int) ->int:
    return ((facs[n] * invs[k]) % MOD * invs[n - k]) % MOD

dp[0][0] = 1
for i in range(1, 27):
    for k in range(0, K + 1):
        # dp[i][k] += dp[i - 1][k]
        for j in range(0, min(C[i - 1], k) + 1):
            dp[i][k] = (dp[i][k] + (dp[i - 1][k - j] * combMod(k, j)) % MOD) % MOD
            
# print(dp)
print(sum(dp[26][1:]) % MOD)
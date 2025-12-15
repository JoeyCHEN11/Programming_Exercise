n = int(input())
MOD = 998244353
q = pow(10, len(str(n)), MOD)

ans = ((n % MOD) * (1 - pow(q, n, MOD)) * pow(1 - q, -1, MOD)) % MOD
print(ans)
# print(pow(1 - q, -1, MOD))
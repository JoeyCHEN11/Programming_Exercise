n, m = map(int, input().split())

L, MOD = 60, 998244353

ans = 0
for i in range(L):
    if m & (1 << i):
        cycles = (n + 1) // (2**(i + 1))
        rest = (n + 1) % (2**(i + 1))
        ans += cycles * 2**i + max(0, rest - 2**i)  
        
ans %= MOD
print(ans)
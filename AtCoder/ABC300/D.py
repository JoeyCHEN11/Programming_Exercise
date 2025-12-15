
def sieve_eratos(n) -> list[bool]:
    n = int(n)
    isPrime = [True] * (n + 1)
    isPrime[0] = isPrime[1] = False
    for f in range(2, int(n**0.5) + 1):
        if isPrime[f]:
            for j in range(f + f, n + 1, f):
                isPrime[j] = False
    return isPrime

n = int(input())

P = [i for i, isp in enumerate(sieve_eratos(n ** 0.5 / (3.4))) if isp]
m = len(P)
# print(P)
ans = 0
for i in range(m):
    j, k = i + 1, m - 1
    while j < k:
        while k > j:
            x = P[i] * P[j] * P[k]
            
            # avoid overflow
            if x > n: 
                k -= 1
                continue
            
            x *= P[i]
            if x > n : 
                k -= 1
                continue
            
            x *= P[k]
            if x > n: 
                k -= 1
                continue
            
            break
        ans += k - j
        j += 1
print(ans)
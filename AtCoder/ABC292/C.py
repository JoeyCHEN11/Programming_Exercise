def get_factors(n) -> list[int]:
    n = int(n)
    factors = [1] * (n + 1)
    factors[0] = factors[1] = 1
    for f in range(1, n + 1):
        if factors[f]:
            for j in range(f + f, n + 1, f):
                factors[j] += 1
    return factors

N = int(input())
factors = get_factors(N)
ans = 0
for i in range(1, N):
    j = N - i
    ans += factors[i] * factors[j]
print(ans)
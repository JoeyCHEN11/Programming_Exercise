n, m, k = map(int, input().split())

tests, results = [0] * m, [''] * m
for i in range(m):
    s = input().split()
    for j in map(int, s[1:-1]):
        tests[i] = tests[i] | (1 << (j - 1))
    results[i] = s[-1]
    
ans = 0
for comb in range(1<<n):
    available = True
    for t, res in zip(tests, results):
        bitsLeft = (comb & t).bit_count()
        if (bitsLeft < k and res == 'o'or 
            bitsLeft >= k and res == 'x'):
            available = False
            break
    ans += available
        
print(ans)

    
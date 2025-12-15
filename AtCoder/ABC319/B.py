n = int(input())

ans = ['-'] * (n + 1) 
for i in range(n + 1):
    for j in range(1, 10):
        if n % j == 0 and i % (n // j) == 0:
            ans[i] = str(j)
            break

print(''.join(ans))
            
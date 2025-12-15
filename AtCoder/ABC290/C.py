N, K = map(int, input().split())
A = set(map(int, input().split()))

ans = K
for k in range(K + 1):
    if k not in A:
        ans = k
        break
print(ans)
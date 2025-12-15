N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
ans = 0
for i in B:
    ans += A[i - 1]
print(ans)

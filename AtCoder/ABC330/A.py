n, l = map(int, input().split())
scores = list(map(int, input().split()))
ans = 0
for a in scores:
    ans += a >= l
print(ans)
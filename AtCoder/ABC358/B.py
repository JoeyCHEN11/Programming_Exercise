n, a = map(int, input().split())
times = list(map(int, input().split()))

ans = [0] * n
ans[0] = times[0] + a
for i in range(1, n):
    if times[i] <= ans[i - 1]:
        ans[i] = ans[i - 1] + a 
    else:
        ans[i] = times[i] + a

for an in ans:
    print(an)
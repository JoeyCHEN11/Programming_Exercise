N, D = map(int, input().split())
time = list(map(int, input().split()))
ans = -1
for i in range(1, N):
    if time[i] - time[i - 1] <= D:
        ans = time[i]
        break
print(ans)
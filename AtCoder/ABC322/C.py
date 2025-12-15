import bisect
n, m = map(int, input().split())
fires = list(map(int, input().split()))
ans = [0] * n

for i in range(n):
    ans[i] = fires[bisect.bisect_left(fires, i + 1)] - 1 - i
    
for a in ans:
    print(a)
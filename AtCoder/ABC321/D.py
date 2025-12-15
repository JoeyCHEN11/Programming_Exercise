from itertools import accumulate
n, m, p = map(int, input().split())
mds = list(map(int, input().split()))
sds = list(map(int, input().split()))

mds.sort()
sds.sort()
sidePref = list(accumulate(sds, initial=0))
i, j, ans = 0, m - 1, 0
while i < n and j >= 0:
    if mds[i] + sds[j] >= p:
        ans += (n - i) * p
        j -= 1
    else:
        ans += sidePref[j + 1] + mds[i] * (j + 1)
        i += 1
        
print(ans)
from itertools import accumulate
import bisect
n, m, p = map(int, input().split())
mds = list(map(int, input().split()))
sds = list(map(int, input().split()))

sds.sort()
sidePref = list(accumulate(sds, initial = 0))
ans = 0
for a in mds:
    mid = bisect.bisect_left(sds, p - a)
    ans += (m - mid) * p + (sidePref[mid] + a * (mid))
    # print(ans)
        
print(ans)
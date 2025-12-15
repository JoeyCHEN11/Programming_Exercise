from itertools import accumulate
n, D, P = map(int, input().split())
fares = list(map(int, input().split()))
fares.sort(reverse = True)
pref = list(accumulate(fares, initial=0))
# print(pref)
noPassDay, batchCnt = n, 0
for d in range(0, n + 1, D):
    if pref[min(d + D, n)] - pref[d] > P:
        batchCnt += 1
    else:
        noPassDay = d
        break

# print(batchCnt)
ans = batchCnt * P + pref[n] - pref[noPassDay]
print(ans)
from itertools import accumulate
import bisect
n, k = map(int, input().split())
medicine = [tuple(map(int, input().split())) for _ in range(n)] + [(0, float('inf'))]
medicine.sort(reverse = True)
# print(medicine)

pref = list(accumulate([x[1] for x in medicine]))
# print(pref)
ki = bisect.bisect_right(pref, k)
# print(ki)
print(medicine[ki][0] + 1)
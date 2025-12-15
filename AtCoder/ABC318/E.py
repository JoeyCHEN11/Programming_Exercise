from collections import defaultdict
from itertools import accumulate
n = int(input())
nums = list(map(int, input().split()))

numIdx = defaultdict(list[int])

for i, a in enumerate(nums):
    numIdx[a].append(i)
    
ans = 0
for idxs in numIdx.values():
    # print(idxs)
    m = len(idxs)
    cnt, acc = 0, 0
    for i in range(m - 1):
        cnt = idxs[i + 1] - idxs[i] - 1
        acc += cnt * (i + 1) * (m - (i + 1))
    ans += acc
print(ans)
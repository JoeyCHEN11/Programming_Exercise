from sortedcontainers import SortedSet
from collections import Counter
n, q = map(int, input().split())
nums = list(map(int, input().split()))
queries = [tuple(map(int, input().split())) for _ in range(q)]

check = Counter(nums)
mexs = SortedSet()
for m in range(n + 1):
    if m not in check:
        mexs.add(m)

for i, x in queries:
    a = nums[i - 1]
    if a <= n:
        check[a] -= 1
        if check[a] == 0:
            mexs.add(a)
    
    nums[i - 1] = x
    if x <= n:
        if check[x] == 0:
            mexs.remove(x)
        check[x] += 1
    
    print(mexs[0])
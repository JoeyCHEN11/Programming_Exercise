from collections import defaultdict
n = int(input())
nums = list(map(int, input().split()))

check = defaultdict(list)
for i, a in enumerate(nums, 1):
    check[a].append(i)

for x, _ in sorted(check.items(), key = lambda x: x[1][1]):
    print(x, end = ' ')
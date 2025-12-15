n = int(input())
nums = list(map(int, input().split()))
ans = []

for i in range(n - 1):
    a1, a2 = nums[i], nums[i + 1]
    step = 1 if a1 < a2 else -1
    ans.extend([x for x in range(a1, a2, step)])
ans.append(nums[-1])
for a in ans:
    print(a, end = ' ')
    
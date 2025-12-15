from itertools import accumulate

n = int(input())
nums = list(zip(list(map(int, input().split())), [i for i in range(n)]))
nums.sort(reverse = True)
# print(nums)
ans = [0] * n
preSum = list(accumulate([nums[i][0] for i in range(n)], initial = 0))
# print(preSum)

for i in range(1, n):
    preIdx, idx = nums[i-1][1], nums[i][1]
    if(nums[i - 1][0] == nums[i][0]):
        ans[idx] = ans[preIdx]
    else:
        ans[idx] = preSum[i]
        
for a in ans:
    print(a, end= ' ')
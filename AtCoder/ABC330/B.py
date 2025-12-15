n, l, r = map(int, input().split())
nums = list(map(int, input().split()))
ans = [0] * n
for i in range(n):
    if l <= nums[i] <= r:
        ans[i] = nums[i]
    elif nums[i] < l:
        ans[i] = l
    else:
        ans[i] = r
        
for a in ans:
    print(a, end=' ')
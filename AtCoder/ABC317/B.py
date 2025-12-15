n = int(input())
nums = sorted(list(map(int, input().split())))

ans = -1
for i in range(n - 1):
    if nums[i + 1] != nums[i] + 1:
        ans = nums[i] + 1
        break
    
print(ans)

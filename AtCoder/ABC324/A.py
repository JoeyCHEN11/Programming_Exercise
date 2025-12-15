n = int(input())
nums = list(map(int, input().split()))

a, same = nums[0], True
for num in nums:
    if a != num:
        same = False   
        break

print('Yes' if same else 'No') 
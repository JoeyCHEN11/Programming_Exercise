n = int(input())
nums = list(map(int, input().split()))
target = sum(nums) // n

over, below = 0, 0

for x in nums:
    if x > target:
        over += x - target - 1
    else:
        below += target - x
        
print(max(below, over))
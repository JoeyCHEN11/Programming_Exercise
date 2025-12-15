nums = list(map(int, input().split()))
n = len(nums)
ok = nums[0] % 25 == 0 and 100 <= nums[0] <= 675

for i in range(1, n):
    if nums[i] < nums[i - 1] or nums[i] % 25 != 0 or not (100 <= nums[0] <= 675):
        ok = False
        break

print('Yes' if ok else 'No')
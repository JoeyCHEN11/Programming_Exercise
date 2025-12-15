N, X = map(int, input().split())
nums = list(map(int, input().split()))
check = set()

ans = False
for a in nums:
    check.add(a)
    if a - X in check or a + X in check:
        ans = True
        break

print('Yes' if ans else 'No')
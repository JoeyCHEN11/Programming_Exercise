from math import ceil
a, b = map(int, input().split())
ans = a // b
if a % b != 0:
    ans += 1
print(ans)
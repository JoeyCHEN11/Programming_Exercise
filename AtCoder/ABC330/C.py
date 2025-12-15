import math
d = int(input())
ans = float('inf')
for x in range(int(d**0.5) + 2):
    c = x * x - d
    if c >= 0:
        ans = min(ans, c)
    else:
        y1 = int((-c)**0.5)
        y2 = y1 + 1
        ans = min(ans, abs(c + y1**2), abs(c + y2**2))

print(ans)
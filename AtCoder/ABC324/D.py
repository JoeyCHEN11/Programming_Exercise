from math import sqrt
n = int(input())
s = sorted(input())

ans = 0
for x in range(int(sqrt(pow(10, n))) + 1):
    x2 = x * x
    x2s = str(x2) + '0' * (n - len(str(x2)))
    # print(sorted(x2s))
    ans += sorted(x2s) == s
       
print(ans)
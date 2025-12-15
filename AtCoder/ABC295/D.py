from collections import defaultdict
s = input()
check = defaultdict(int)
parity = 0
check[parity] += 1
for d in s:
    parity = parity ^ 1 << int(d)
    check[parity] += 1

ans = 0
for cnt in check.values():
    ans += cnt * (cnt - 1) // 2
print(ans)

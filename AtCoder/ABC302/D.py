import bisect
N, M, D = map(int, input().split())
aoki = list(map(int, input().split()))
snuke = list(map(int, input().split()))

snuke.sort()
# aoki.sort()
ans = -1
for a in aoki:
    bi = bisect.bisect_right(snuke, a + D)
    if abs(snuke[bi - 1] - a) <= D:
        ans = max(ans, a + snuke[bi - 1])

# for b in snuke:
#     ai = bisect.bisect_right(aoki, b + D)
#     if abs(aoki[ai - 1] - b) <= D:
#         ans = max(ans, b + aoki[ai - 1])
    
print(ans)
import bisect
n, t = map(lambda x: int(x) if x.isdecimal() else x, input().split())
text = [input() for _ in range(n)]
preLen = [0 for _ in range(n)]

for i, s in enumerate(text):
    j = 0
    for c in s:
        if t[j] == c:
            j += 1
        if j >= len(t):
            break
    preLen[i] = j

preLen.sort()

# print(preLen)
ans = 0
for s in text:
    j = len(t) - 1
    cnt = 0
    for c in reversed(s):
        if t[j] == c:
            j -= 1
            cnt += 1
        if j < 0:
            break
    ans += n - bisect.bisect_left(preLen, j + 1)
print(ans)
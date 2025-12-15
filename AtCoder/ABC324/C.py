n, trec = input().split()
n = int(n)
text = [input() for _ in range(n)]

def findDiff(s: str, t: str) -> int:
    if len(s) < len(t): s, t = t, s
    cnt = 0
    j = 0
    for i in range(len(s)):
        if s[i] == t[j]:
            j += 1
        else:
            cnt += 1
            if len(s) == len(t):
                j += 1
        if j >= len(t):
            break
    return cnt

ans = []
for i, st in enumerate(text, 1):
    if abs(len(st) - len(trec)) <= 1 and findDiff(st, trec) <= 1:
        ans.append(i)

print(len(ans))
for idx in ans:
    print(idx, end=' ')
    
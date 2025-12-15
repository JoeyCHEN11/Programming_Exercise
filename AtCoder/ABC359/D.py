n, k = map(int, input().split())
s = input()
MOD = 998244353
def isParlindrome(t: str) -> bool:
    return t == t[::-1]

allP = []
for i in range(1 << k):
    t = []
    for j in range(k):
        t.append('A' if (i >> j) & 1 else 'B')
    st = ''.join(t)
    if isParlindrome(st): allP.append(st)
    
print(allP)
choices = [dict() for _ in range(n)]
for i, c in enumerate(s):
    choice = {'A': 0, 'B': 0}
    if c != '?':
        choice[c] += 1
    else:
        choice['A'] = choice['B'] = 1
    choices[i] = choice

for i in range(n - k + 1):
    print('check', i)
    for p in allP:
        ok = True
        # print(p)
        for j in range(k):
           if s[i + j] != '?' and p[j] != s[i + j]:
               ok = False
               break
        if ok:
            print('match:', p)
            for j in range(k):
                if s[j] == '?':
                    choices[i + j][p[j]] = 0
    
ans = 1
for c in choices:
    ans = (ans * sum(c.values())) % MOD

print(ans)

        
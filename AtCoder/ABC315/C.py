n = int(input())
f_s = [tuple(map(int, input().split())) for _ in range(n)]
f_s.sort(key= lambda x: (x[0], -x[1]))
sameMax = 0
for i in range(n - 1):
    if i > 0 and f_s[i - 1][0] == f_s[i][0]:
        continue
    if f_s[i][0] == f_s[i + 1][0]:
        s1, s2 = f_s[i][1], f_s[i + 1][1]
        sameMax = max(sameMax, s1 + s2 // 2)

maxS = [0] * n
for f, s in f_s:
    maxS[f - 1] = max(maxS[f - 1], s)
maxS.sort(reverse=True)
diffMax = maxS[0] + maxS[1]

print(max(sameMax, diffMax))

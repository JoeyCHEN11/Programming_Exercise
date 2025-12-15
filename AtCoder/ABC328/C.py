from itertools import accumulate
n, q = map(int, input().split())
s = input()
queries = [tuple(map(int, input().split())) for _ in range(q)]

conseqs = [0] * n

for i in range(n - 1):
    if s[i] == s[i + 1]:
        conseqs[i] = 1
        
pre = list(accumulate(conseqs, initial= 0))
# print(pre)
for (l, r) in queries:
    print(pre[r - 1] - pre[l - 1])


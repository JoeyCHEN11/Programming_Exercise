from collections import deque
n, m = map(int, input().split())
s = input()
colors = list(map(lambda x: int(x) - 1, input().split()))
cque = [deque() for _ in range(m)]
for i, c in enumerate(colors):
    cque[c].append(s[i])

for i in range(m):
    ch = cque[i].pop()
    cque[i].appendleft(ch)
    
ans = [''] * n
for i, c in enumerate(colors):
    ans[i] = cque[c].popleft()

print(''.join(ans))
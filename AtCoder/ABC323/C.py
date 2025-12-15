n, m = map(int, input().split())
A = list(map(int, input().split()))
states = [input() for _ in range(n)]
scores = [i for i in range(1, n + 1)]

for i in range(n):
    for j in range(m):
        if states[i][j] == 'o':
            scores[i] += A[j]

stA_idx = sorted(zip(A, [i for i in range(m)]), reverse = True)
maxS = max(scores)
# print(stA_idx)
ans = [0] * n
for i in range(n):
    sc, idx, cnt = scores[i], 0, 0
    while sc < maxS:
        a, j = stA_idx[idx]
        if states[i][j] == 'x':
            sc += a
            cnt += 1
        idx += 1
    ans[i] = cnt
    
for an in ans:
    print(an)
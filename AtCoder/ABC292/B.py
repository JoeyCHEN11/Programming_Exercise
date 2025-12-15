N, Q = map(int, input().split())
queries = [tuple(map(int, input().split())) for _ in range(Q)]

yellows = [0] * (N + 1)
removed = [False] * (N + 1)

ans = []
for c, x in queries:
    if c == 1:
        yellows[x] += 1
        if yellows[x] >= 2:
            removed[x] = True
    elif c== 2:
        removed[x] = True
    else:
        ans.append(removed[x])
for a in ans:
    print('Yes' if a else 'No')

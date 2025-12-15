from collections import deque
n, q = list(map(int, input().split()))
queries = [tuple(map(lambda x : int(x) if x.isdigit() else x , input().split())) for _ in range(q)]
# print(queries)
directs = {'R': (1, 0), 'L': (-1, 0), 'U':(0, 1), 'D':(0, -1)}
loong = [(i, 0) for i in range(1, n + 1)][::-1]

for cat, query in queries:
    if cat == 1:
        x, y = loong[-1]
        dx, dy = directs[query]
        loong.append((x + dx, y + dy))
    else:
        x, y = loong[-query]
        print(x, y)
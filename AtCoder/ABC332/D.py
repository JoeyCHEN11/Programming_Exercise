from collections import deque
from copy import deepcopy
h, w = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(h)]
B = [list(map(int, input().split())) for _ in range(h)]


def toTuple(grid: list[list]):
    return tuple(tuple(row) for row in grid)

# bfs
distance = {toTuple(A): 0}
que = deque([A])
cnt = -1
while que:
    u = que.popleft()
    d = distance[toTuple(u)]
    
    # find target
    if u == B:
        cnt = d
        break

    else:
        # swap rows
        for i in range(h - 1):
            v = deepcopy(u)
            v[i], v[i + 1] = v[i + 1], v[i]
            if toTuple(v) not in distance:
                distance[toTuple(v)] = d + 1
                que.append(v)
        
        # swap columns
        for j in range(w - 1):
            v = deepcopy(u)
            for i in range(h):
                v[i][j], v[i][j + 1] = v[i][j + 1], v[i][j]
            if toTuple(v) not in distance:
                distance[toTuple(v)] = d + 1
                que.append(v)
            
print(cnt)
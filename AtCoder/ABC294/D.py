from sortedcontainers import SortedSet
N, Q = map(int, input().split())
events = [tuple(map(int, input().split())) for _ in range(Q)]

waiting = [i for i in range(N, 0, -1)]
called = SortedSet()
ans = []
for e in events:
    if e[0] == 1:
        called.add(waiting.pop())
    elif e[0] == 2:
        called.remove(e[1])
    else:
        ans.append(called[0])
for x in ans:
    print(x)
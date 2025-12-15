from sortedcontainers import SortedList, SortedSet
from collections import defaultdict
N, Q = int(input()), int(input())
queries = [tuple(map(int, input().split())) for _ in range(Q)]
boxes = [SortedList() for _ in range(N + 1)]
cards = defaultdict(SortedSet)

for q in queries:
    tp = q[0]
    if tp == 1:
        _, i, j = q
        boxes[j].add(i)
        cards[i].add(j)
    elif tp == 2:
        _, i = q
        for c in boxes[i]:
            print(c, end=' ')
        print()
    elif tp == 3:
        _, i = q
        for b in cards[i]:
            print(b, end=' ')
        print()


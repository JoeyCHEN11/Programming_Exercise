from sortedcontainers import SortedList
n, k, q = map(int, input().split())
queries = [tuple(map(int, input().split())) for _ in range(q)]
A = [0] * n
ans = 0
ss = SortedList(A)

for x, y in queries:
    ss.remove(A[x - 1])
    A[x - 1] = y
    ss.add(y)
    print(sum(ss[n - k:]))
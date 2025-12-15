from sortedcontainers import SortedList
n, k, q = map(int, input().split())
queries = [tuple(map(int, input().split())) for _ in range(q)]

ans = 0
A = [0] * n
ss = SortedList(A)
for x, y in queries:
    reVal, repos = A[x - 1], ss.bisect_left(A[x - 1])
    kpos, kLar = n - k, ss[n - k]
    
    A[x - 1] = y
    ss.remove(reVal)
    ss.add(y)
    ans -= reVal if repos >= kpos else kLar
    ans += y if y > kLar else ss[kpos]
    print(ans)
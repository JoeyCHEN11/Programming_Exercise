import bisect
n = int(input())
A = list(map(int, input().split()))
Q = int(input())
queries = [tuple(map(int, input().split())) for _ in range(Q)]

pref = [0] * n
for i in range(1, n):
    pref[i] = pref[i - 1] if i & 1 else pref[i - 1] + A[i] - A[i - 1]
for l, r in queries:
    ans = 0
    li, ri = bisect.bisect_left(A, l), bisect.bisect_left(A, r)
    ans = pref[ri] - pref[li]
    if not li & 1:
        ans += A[li] - l
    if not ri & 1:
        ans -= A[ri] - r
    print(ans)
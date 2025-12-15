import bisect

N, Q = map(int, input().split())

R = sorted(list(map(int, input().split())))
queries = [int(input()) for _ in range(Q)]

preSum = [0] * (N + 1)

for i in range(1, N + 1):
    preSum[i] = preSum[i - 1] + R[i - 1]

# preSum.append(float('inf'))
for que in queries:
    cnt = bisect.bisect_right(preSum, que)
    print(cnt - 1)

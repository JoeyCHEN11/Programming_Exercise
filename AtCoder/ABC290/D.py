from math import lcm
T = int(input())
tests = [tuple(map(int, input().split())) for _ in range(T)]

ans = [0] * T
for i, (N, D, K) in enumerate(tests):
    t = lcm(N, D) // D
    k = K - 1
    ans[i] = k//t + ((k % t)* D) % N

for a in ans:
    print(a)


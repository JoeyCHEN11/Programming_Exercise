from collections import deque
Q = int(input())
queries = [tuple(map(int, input().split())) for _ in range(Q)]

MOD = 998244353
ans, expM = 1, 1
nums = deque([1])
for q in queries:
    if q[0] == 1:
        x = q[1]
        nums.append(x)
        ans = ((ans * 10) % MOD + x) % MOD
        expM = (expM * 10) % MOD
    elif q[0] == 2:
        d = nums.popleft()
        ans = (ans - (d * expM) % MOD) % MOD
        expM = (expM * pow(10, -1, MOD)) % MOD
    else:
        print(ans)


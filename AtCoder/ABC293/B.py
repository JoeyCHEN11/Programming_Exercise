N = int(input())
nums = list(map(lambda x: int(x) - 1, input().split()))
called = [False] * N

for i in range(N):
    if not called[i]:
        called[nums[i]] = True

ans = [i + 1 for i, c in enumerate(called) if not c]
print(len(ans))
for x in ans:
    print(x, end=' ')
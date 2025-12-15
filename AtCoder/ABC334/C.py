N, K = map(int, input().split())
lost = list(map(int, input().split()))

preSum = [0] * (K + 1)
sufSum = [0] * (K + 1)

for i in range(2, K + 1):
    preSum[i] = preSum[i - 1]
    if(i % 2 == 0):
        preSum[i] += lost[i - 1] - lost[i - 2]

for i in range(K - 2, -1, -1):
    sufSum[i] = sufSum[i + 1]
    if (K - i) % 2 == 0:
        sufSum[i] += lost[i + 1] - lost[i]

# print(preSum)
# print(sufSum)
if K % 2 == 0:
    ans = preSum[K]
else:
    ans = float('inf')
    for i in range(0, K, 2):
        ans = min(ans, preSum[i] + sufSum[i])

print(ans)
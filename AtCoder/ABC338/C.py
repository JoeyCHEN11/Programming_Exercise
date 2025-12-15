n = int(input())
ingreds = tuple(map(int, input().split()))
dishA = tuple(map(int, input().split()))
dishB = tuple(map(int, input().split()))

INF = 10**18

ans = 0
for x in range(max(ingreds) + 1):
    y = INF
    for i in range(n):
        if ingreds[i] - x * dishA[i] < 0:
            y = -INF
        elif dishB[i] > 0:
            y = min(y, (ingreds[i] - x * dishA[i]) // dishB[i])
    if y == -INF: break
    ans = max(ans, x + y)

print(ans)
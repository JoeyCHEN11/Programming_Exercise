n = int(input())
scores = list(map(int, input().split()))
if n <= 1:
    print(0)
else:
    maxS = max(scores[1:])
    print(max(maxS - scores[0] + 1, 0))
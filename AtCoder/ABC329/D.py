from collections import defaultdict
n, m = map(int, input().split())
votes = list(map(int, input().split()))

result = defaultdict(int)
maxVotes, maxIdx = 0, -1
for v in votes:
    result[v] = result[v] + 1
    if result[v] > maxVotes or result[v] == maxVotes and v < maxIdx:
        maxVotes = result[v]
        maxIdx = v
    print(maxIdx)
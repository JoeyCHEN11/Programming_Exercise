n = int(input())
edges = list(map(lambda x: int(x) - 1, input().split()))

u = 0
visited, seq = [False] * n, []

while not visited[u]:
    visited[u] = True
    seq.append(u)
    u = edges[u]
    

ans = seq[seq.index(u):]

print(len(ans))
for a in ans:
    print(a + 1, end=' ')
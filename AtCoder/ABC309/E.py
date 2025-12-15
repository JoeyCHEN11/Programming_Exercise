from collections import deque
n, m = map(int, input().split())
tree =[[] for _ in range(n)]
for i, p in enumerate(map(int, input().split()), 1):
    tree[p - 1].append(i)
covered = [False] * n
maxCovers = [-1] * n
for _ in range(m):
    x, y = map(int, input().split())
    maxCovers[x - 1] = max(maxCovers[x - 1], y)
# print(tree)
def bfs(r: int):
    que = deque([r])
    while que:
        u = que.popleft()
        if maxCovers[u] >= 0:
            covered[u] = True
        
        for v in tree[u]:
            maxCovers[v] = max(maxCovers[v], maxCovers[u] - 1)
            que.append(v)

bfs(0)
print(sum(covered))
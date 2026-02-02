N = int(input())
adj = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)
d = [0] * (N + 1)
f = [0] * (N + 1)
dfs_stk = []
t = 0

for _ in range(N):
    info = list(map(int, input().split()))
    u, k = info[0], info[1]
    if k > 0:
        adj[u] += info[2:]
    
def find_next(u, pos):
    while pos < len(adj[u]):
        v = adj[u][pos]
        pos += 1
        if not visited[v]:
            dfs_stk[-1] = (u, pos)
            return v
    dfs_stk[-1] = (u, pos)
    return 0


def dfs(r):
    global t
    dfs_stk.append((r, 0))
    t += 1
    d[r] = t
    visited[r] = True
    while dfs_stk:
        u, pos = dfs_stk[-1]

        v = find_next(u, pos)
        if v != 0:
            t += 1
            d[v] = t
            visited[v] = True

            dfs_stk.append((v, 0))
        else:
            t += 1
            f[u] = t
            dfs_stk.pop()

# dfs
for u in range(1, N + 1):
    if not visited[u]:
        dfs(u)

for i in range(1, N + 1):
    print(i, d[i], f[i])
from collections import deque

N = int(input())
G = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)
dis_1 = [-1] * (N + 1)

for _ in range(N):
    info = list(map(int, input().split()))
    u, k = info[0], info[1]
    if k > 0:
        G[u] += info[2:]
    

def bfs(r):
    bfs_que = deque()
    visited[r] = True
    dis_1[r] = 0
    bfs_que.append(r)
    while bfs_que:
        u = bfs_que.popleft()
        
        # end visit (turn black)
        
        for v in G[u]:
            if not visited[v]:
                visited[v] = True
                dis_1[v] = dis_1[u] + 1
                bfs_que.append(v)

bfs(1)

# for u, d in enumerate(dis_1[1:], 1):
#     print(u, d)

print('\n'.join(f"{u} {d}" for u, d in enumerate(dis_1[1:], 1)))
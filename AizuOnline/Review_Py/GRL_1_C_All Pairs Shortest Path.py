from copy import deepcopy
V, E = map(int, input().split())
G = [[float('inf')] * V for _ in range(V)]

for _ in range(E):
    u, v, w = map(int, input().split())
    G[u][v] = w

G_Dis = [[G[i][j] if i != j else 0 for j in range(V)] for i in range(V)]

# for line in G_Dis:
#     print(line)

for k in range(V):
    for i in range(V):
        for j in range(V):
            G_Dis[i][j] = min(G_Dis[i][j], G_Dis[i][k] + G_Dis[k][j])

if any([G_Dis[i][i] < 0 for i in range(V)]):
    print("NEGATIVE CYCLE")
else:
    for i in range(V):
        print(*[G_Dis[i][j] if G_Dis[i][j] != float('inf') else "INF" for j in range(V)])
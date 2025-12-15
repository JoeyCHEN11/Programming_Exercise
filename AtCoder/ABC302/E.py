N, Q = map(int, input().split())
graph = [set() for _ in range(N)]
queries = [tuple(map(int, input().split())) for _ in range(Q)]

ans = N

for q in queries:
    if q[0] == 1:
        _, u, v = q
        u, v = u - 1, v - 1
        ans -= (int(not graph[u]) + int(not graph[v]))
        
        graph[u].add(v)
        graph[v].add(u)
    else:
        _, u = q
        u -= 1
        for v in graph[u]:
            graph[v].remove(u)
            if not graph[v]:
                ans += 1
        if graph[u]: ans += 1
        graph[u].clear()
    print(ans)
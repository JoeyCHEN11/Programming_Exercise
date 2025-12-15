from atcoder.scc import SCCGraph

n = int(input())
edges = list(map(lambda x: int(x) - 1, input().split()))
# print(edges) 
graph = [[] for _ in range(n)]
parent = [-1] * n

sccg = SCCGraph(n)
for u, v in enumerate(edges):
    # graph[u].append(v)
    sccg.add_edge(u, v)


ans = []
for comp in sccg.scc():
    if len(comp) >= 2:
        nodes = set(comp)
        u = comp[0]
        ans.append(u)
        nodes.remove(u)
        while nodes:
            u = edges[u]
            ans.append(u)
            nodes.remove(u)
        break
print(len(ans))
for a in ans:
    print(a + 1, end= ' ')

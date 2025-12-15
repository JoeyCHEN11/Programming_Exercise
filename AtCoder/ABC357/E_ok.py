from atcoder.scc import SCCGraph
n = int(input())
edges = list(map(int, input().split()))
rechCnt = [0] * n # rc[i]: how many nodes are reachable from node i
sccs = SCCGraph(n)
for u in range(n):
    v = edges[u] - 1
    sccs.add_edge(u, v)

for sComp in sccs.scc()[::-1]:
    if len(sComp) > 1:
        for u in sComp:
            rechCnt[u] = len(sComp)
    else:
        u, v = sComp[0], edges[sComp[0]] - 1
        rechCnt[u] = rechCnt[v] + 1
        
print(sum(rechCnt))
from collections import deque
n = int(input())
graph = list(map(lambda x: int(x) - 1, input().split()))
indeg = [0] * n
reachCnt = [0] * n
visited = [False] * n
topo = deque()

for v in graph:
    indeg[v] += 1
        
def topoSort():
    def topoBfs(r: int):
        que = deque([r])
        visited[r] = True
        topo.append(r)
        
        while que:  
            u = que.popleft()
            
            v = graph[u]
            indeg[v] -= 1
            # print(indeg)
            if indeg[v] == 0:
                visited[v] = True
                topo.append(v)
                # print(topo)
                que.append(v)
    
    for r, vis in enumerate(visited):
        if not vis and indeg[r] == 0:
            # print('visit:', r)
            topoBfs(r)
            
    for u, ind in enumerate(indeg):
        if ind != 0:
            topo.append(u)        

def sccCnt():
    def sccDfs(u: int, depth: int) -> int:
        visited[u] = True
        v = graph[u]
        
        if not visited[v]:
            maxCnt = sccDfs(v, depth + 1)
        else:
            maxCnt = depth + reachCnt[v]
        reachCnt[u] = maxCnt
        return maxCnt
    
    def sccBfs(r: int):
        reachable = 0
        cnt = 1
        que = deque([r])
        cycNode = [r]
        reachCnt[r] = 1
        
        while que:
            u = que.popleft()
            v = graph[u]
            
            if reachCnt[v] == 0:
                cycNode.append(v)
                cnt += 1
                reachCnt[v] = 1
                que.append(v)
            elif cnt == 1 and u != v:
                # print('find rech')
                reachable += reachCnt[v]

        for u in cycNode:
            reachCnt[u] = reachable + cnt
            
    for r in reversed(topo):
        if reachCnt[r] == 0:
            sccBfs(r)
            # sccDfs(r, 1)

topoSort()
sccCnt()
print(sum(reachCnt))
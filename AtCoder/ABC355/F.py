import heapq
class DisjointSet:
    def __init__(self, n: int) -> None:
        self.rank = [0] * n
        self.forest = [x for x in range(n)]
        self.setNum = n

    def makeSet(self, x: int):
        self.forest[x] = x
        self.rank[x] = 0

    #combine tow sets
    #if they are in the same set, do nothing.
    def unite(self, x: int, y: int):
        self.linkTree(self.findSet(x),self.findSet(y))
        
    # Do not use this directly
    def linkTree(self, x: int, y: int):
        if x == y: return
        if self.rank[x] < self.rank[y]: self.forest[x] = self.forest[y]
        else:
            if self.rank[x] == self.rank[y]: self.rank[x] += 1
            self.forest[y] = self.forest[x]
        self.setNum -= 1
    
    def findSet(self, x: int):
        if self.forest[x]!=x: self.forest[x] = self.findSet(self.forest[x])
        return self.forest[x]
    
    def same(self, x: int, y: int):
        return self.findSet(x) == self.findSet(y)

n, q =  map(int, input().split())

#          a, b, c
edges = [tuple(map(int, input().split())) for _ in range(n - 1)]
#           u, v, w
queries = [tuple(map(int, input().split())) for _ in range(q)]

mstEdgesHP = [[] for _ in range(n + 1)]
mstGraph = [[0] * (n + 1) for _ in range(n + 1)]
mstSum = 0


ds = DisjointSet(n + 1)
edges.sort(key = lambda x: x[2])
# print('edges: ')
# print(edges)
for a, b, c in edges:
    if not ds.same(a, b):
        ds.unite(a, b)
        mstSum += c
        mstEdgesHP[a].append((-c, b))
        mstEdgesHP[b].append((-c, a))
        mstGraph[a][b] = c
        mstGraph[b][a] = c
            
# print(mstEdgesHP)
for es in mstEdgesHP:
    heapq.heapify(es)
    # print(heapq.heappop(es) if es else 0)

ans = []

for u, v, w in queries:
    print(u, v, w)
    maxEUC, maxEUt = -mstEdgesHP[u][0][0], mstEdgesHP[u][0][1]
    maxEVC, maxEVt = -mstEdgesHP[v][0][0], mstEdgesHP[v][0][1]
    while(maxEUC != mstGraph[u][maxEUt]):
        print('check U:')
        print(mstEdgesHP)
        heapq.heappop(mstEdgesHP[u])
        maxEUC, maxEUt = -mstEdgesHP[u][0][0], mstEdgesHP[u][0][1]
    while(maxEVC != mstGraph[v][maxEVt]):
        print('check V:')
        print(mstEdgesHP)
        heapq.heappop(mstEdgesHP[v])
        maxEVC, maxEVt = -mstEdgesHP[v][0][0], mstEdgesHP[v][0][1]
    # heapq.heappop(mstEdgesHP[u])
    # heapq.heappop(mstEdgesHP[v])
    
    deletC, deletS, deletT = max((maxEUC, u, maxEUt), (maxEVC, v, maxEVt), (w, u, v))
    if deletS != u or deletT != v:
        mstSum -= deletC
        mstSum += w
        
        mstGraph[deletS][deletT] = 0
        mstGraph[deletT][deletS] = 0
        
        mstGraph[u][v] = w
        mstGraph[v][u] = w        
        heapq.heappush(mstEdgesHP[u], (-w, v))
        heapq.heappush(mstEdgesHP[v], (-w, u))
        
    ans.append(mstSum)
        

for an in ans:
    print(an)

    




# print(bingoTurn)
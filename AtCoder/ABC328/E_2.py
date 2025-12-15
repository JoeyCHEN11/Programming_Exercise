from itertools import combinations
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

n, m, k = map(int, input().split())
edges = []

for _ in range(m):
    u, v, w = map(int, input().split())
    edges.append((u - 1, v - 1, w))

ans = k + 1
for comb in combinations(edges, n - 1):
    # print(comb)
    # print('built, stedge:',stEdge)
    mst = 0
    ds = DisjointSet(n)
    for (u, v, w) in comb:
        if ds.same(u, v):
            # print('failed')
            mst = k + 1
            break
        else:
            ds.unite(u, v)
            mst = (mst + w) % k
    ans = min(mst, ans)

print(ans)
    
     

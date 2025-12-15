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

N, M = map(int, input().split())
edges = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]

ds = DisjointSet(N)
comp_v, comp_e = [0] * N, [0] * N
for u, v in edges:
    ds.unite(u, v)
    
for v in range(N):
    comp_v[ds.findSet(v)] += 1

for e, _ in edges:
    comp_e[ds.findSet(e)] += 1
    
print('Yes' if comp_e == comp_v else 'No')
    

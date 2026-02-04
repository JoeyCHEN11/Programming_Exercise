class DisjointSet:
    def __init__(self, n: int) -> None:
        self.rank = [0] * n
        self.forest = [x for x in range(n)]
        self.setNum = n

    def makeSet(self, x: int):
        self.forest[x] = x
        self.rank[x] = 0


    def unite(self, x: int, y: int):
        """
        combine tow sets
        if they are in the same set, do nothing.
        """
        self.linkTree(self.findSet(x),self.findSet(y))
        
    # 
    def linkTree(self, x: int, y: int):
        """
        Do not use this directly
        """
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

V, E = map(int, input().split())

edges = []
ds = DisjointSet(V)

for _ in range(E):
    u, v, w = map(int, input().split())
    edges.append((w, u, v))

edges.sort()
mst_cost = 0

for w, u, v in edges:
    if not ds.same(u, v):
        mst_cost += w
        ds.unite(u, v)

print(mst_cost)

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
stEdge = []
def backTrack(idx: int, depth: int):
    global ans

    if depth >= n - 1:
        # print('built, stedge:',stEdge)
        mst = 0
        ds = DisjointSet(n)
        for (u, v, w) in stEdge:
            if ds.same(u, v):
                # print('failed')
                return
            else:
                ds.unite(u, v)
                mst += w
        ans = min(mst % k, ans)
        return

    if idx > m - (n - 1 - depth): return
    
    u, v, w = edges[idx]
    stEdge.append((u, v, w))
    backTrack(idx + 1, depth + 1)
    stEdge.pop()
    backTrack(idx + 1, depth)
    
def backTrackLoop(depth: int):
    global ans

    if depth >= n - 1:
        # print('built, stedge:',stEdge)
        mst = 0
        ds = DisjointSet(n)
        for (u, v, w) in stEdge:
            if ds.same(u, v):
                # print('failed')
                return
            else:
                ds.unite(u, v)
                mst += w
        ans = min(mst % k, ans)
        return
    
    for i in range(depth, m - (n - 1 - depth) + 1):
        u, v, w = edges[i]
        stEdge.append((u, v, w))
        backTrackLoop(depth + 1)
        stEdge.pop()
        
# backTrack(0, 0)
backTrackLoop(0)
print(ans)
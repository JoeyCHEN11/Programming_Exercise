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
edges = [tuple(map(int, input().split())) for _ in range(M)]
K = int(input())
x_y = [tuple(map(int, input().split())) for _ in range(K)]
Q = int(input())
queries = [tuple(map(int, input().split())) for _ in range(Q)]

ds = DisjointSet(N)
for u, v in edges:
    ds.unite(u - 1, v - 1)

bad_roots = set(tuple(sorted((ds.findSet(x - 1), ds.findSet(y - 1)))) for x, y in x_y)
# print(bad_roots)

for p, q in queries:
    roots = tuple(sorted((ds.findSet(p - 1), ds.findSet(q - 1))))
    print('Yes' if roots not in bad_roots else 'No')
NIL = -1

class Point:
    def __init__(self, id, x = 0, y = 0) -> None:
        self.x = x
        self.y = y
        self.id = id
        pass
    
    def __lt__(self, other: 'Point'):
        return self.id < other.id
    
    def __iter__(self):
        yield self.id
        yield self.x
        yield self.y
        
class Node:
    def __init__(self, idx = NIL, left = 0, right = 0) -> None:
        # pos in sorted points
        self.idx = idx
        self.left = left
        self.right = right
        pass
    def __iter__(self):
        yield self.idx
        yield self.left
        yield self.right


class TwoDTree:
    def __init__(self, pointsXY: list[tuple[int, int]]) -> None:
        self.n = len(pointsXY)
        self.points = [Point(i, x, y) for i, (x, y) in enumerate(pointsXY)]
        self.tree = [Node() for _ in range(self.n)]
        self.nodeIdx = 0
        self.make2DTree(0, self.n, 0)
        # for idx, l, r in self.tree:
        #     print(idx, l, r)
    
    def make2DTree(self, left, right, depth) -> int:
        if left >= right:
            return NIL
        
        if depth & 1:
            self.points[left:right] = sorted(self.points[left:right], key = lambda p: p.y)
        else:
            self.points[left:right] = sorted(self.points[left:right], key = lambda p: p.x)
        
        mid = (left + right) // 2
        i = self.nodeIdx
        self.nodeIdx += 1
        self.tree[i].idx = mid
        self.tree[i].left = self.make2DTree(left, mid, depth + 1)
        self.tree[i].right = self.make2DTree(mid + 1, right, depth + 1)
        return i
    
    # find all point id which p.x in [sx, tx] and p.y in [sy, ty], from the node u in 2dtree
    def find(self, u: int, sx: int, tx: int, sy: int, ty: int, depth: int, ans: list[int]):
        # print(self.tree[u])
        i, left, right = self.tree[u]
        pid, x, y = self.points[i]
        # print(left, right)
        
        if sx <= x <= tx and sy <= y <= ty:
            ans.append(pid)
        
        # y sorted
        if depth & 1:
            if left != NIL and y >= sy:
                self.find(left, sx, tx, sy, ty, depth + 1, ans)
            if right != NIL and y <= ty:
                self.find(right, sx, tx, sy, ty, depth + 1, ans)
        else:
            if left != NIL and x >= sx:
                self.find(left, sx, tx, sy, ty, depth + 1, ans)
            if right != NIL and x <= tx:
                self.find(right, sx, tx, sy, ty, depth + 1, ans)
                
if __name__ == '__main__':
    n = int(input())
    points = [tuple(map(int, input().split())) for _ in range(n)]
    q = int(input())
    queries = [tuple(map(int, input().split())) for _ in range(q)]
    
    kdTree = TwoDTree(points)
    for sx, tx, sy, ty in queries:
        ans = []
        kdTree.find(0, sx, tx, sy, ty, 0, ans)
        for a in sorted(ans):
            print(a)
        print()

            
    
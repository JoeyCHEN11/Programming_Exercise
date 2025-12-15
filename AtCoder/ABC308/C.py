n = int(input())

class Tose:
    def __init__(self, a: int, b: int, idx: int):
        self.a = a
        self.b = b
        self.idx = idx
        
    def __lt__(self, other: 'Tose'):
        ai, bi, _ = self
        aj, bj, _ = other
        return ai * (aj + bj) < aj * (ai + bi)
            
    def __iter__(self):
        yield self.a
        yield self.b
        yield self.idx

tosses = [Tose(*(tuple(map(int, input().split())) + (i + 1,))) for i in range(n)]
        
tosses.sort(reverse = True)
for _, _, i in tosses:
    print(i,end=' ')    

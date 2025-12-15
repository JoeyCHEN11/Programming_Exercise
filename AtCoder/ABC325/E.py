import heapq
from typing import Callable
n, a, b, c = map(int, input().split())
distances = [list(map(int, input().split())) for _ in range(n)]
graphLis = [[] for _ in range(n)]
# from 0 to i
dCar = [float('inf')] * n
# from i to n - 1
dTrain = [float('inf')] * n 

for u, line in enumerate(distances):
    for v, d in enumerate(line):
        graphLis[u].append((v, d))

#dislis should be (v, weight)
def dijkstraPQ(r: int, disLis: list[int], gLis: list[list[int]], wfunc: Callable[[int], int] = lambda x : x):
    pq = [(0, r)]
    disLis[r] = 0
    while pq:
        du, u = heapq.heappop(pq)
        
        if du > disLis[u]: continue
        
        for v, w in gLis[u]:
            if du + wfunc(w) < disLis[v]:
                disLis[v] = du + wfunc(w)
                heapq.heappush(pq, (disLis[v], v))
            
dijkstraPQ(0, dCar, graphLis, lambda x: a * x)
dijkstraPQ(-1, dTrain, graphLis, lambda x: b * x + c)

ans = float('inf')
for i in range(n):
    ans = min(ans, dCar[i] + dTrain[i] )
    
print(ans)
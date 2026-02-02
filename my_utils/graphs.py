from typing import Callable
from collections import deque
import heapq


def dijkstraMat(r: int, disLis: list[int], gMat: list[list[int]], wfunc: Callable[[int], int] = lambda x : x):
    n = len(gMat)
    WHITE, GRAY, BLACK = 0, 1, 2
    color = [WHITE] * n
    color[r] = GRAY
    disLis[r] = 0
    while True:
        d, u = float('inf'), -1
        for i in range(n):
            if color[i] == GRAY and d > disLis[i]:
                d = disLis[i]
                u = i
        
        if u == -1: break
        
        color[u] = BLACK
        
        for v, w in enumerate(gMat[u]):
            if color[v] != BLACK and d + wfunc(w) < disLis[v]:
                disLis[v] = d + wfunc(w)
                color[v] = GRAY

# v in graph[u] should be (v, weight)
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
            
    
def topoSort(graph: list[list[int]]) -> list[int]:
    n = len(graph)
    inDegree = [0] * n
    for u in range(n):
        for v in graph[u]:
            inDegree[v] += 1
    
    que = deque()
    ans = []
    for i in range(n):
        if inDegree[i] == 0:
            que.append(i)
            ans.append(i)
            
    while que:
        u = que.popleft()
        
        for v in graph[u]:
            inDegree[v] -= 1
            if inDegree[v] == 0:
                ans.append(v)
                que.append(v)
    return ans

if __name__ == '__main__':
    n, e = map(int, input().split())
    graph = [[] for _ in range(n)]
    for _ in range(e):
        u, v = map(int, input().split())
        graph[u].append(v)
    topoAns = topoSort(graph)
    for u in topoAns:
        print(u)
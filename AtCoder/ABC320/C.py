from itertools import permutations

M = int(input())
S = [input() * 2  for _ in range(3)]
INF = float('inf')
def setNum(permu: list, t: str) -> int: 
    if any([not t in S[i] for i in range(3)]): return INF
    time_slot = 0
    # ans = INF
    for i in permu:
        time_slot += S[i][time_slot % M:].find(t)
        time_slot += 1
        
    # if all(found):
    #     ans = time_slot - 1
    return time_slot - 1
        
ans = INF
for d in range(10):
    for p in permutations(range(3)):
        ans = min(ans, setNum(p, str(d)))
    
print(-1 if ans == INF else ans)
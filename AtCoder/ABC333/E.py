from itertools import accumulate
n = int(input())
events = [tuple(map(int, input().split())) for _ in range(n)]
preDiff = [0] * n
picks = [-1] * n
potions = [[] for _ in range(n + 1)]

def beatAdvs() -> bool:
    for idx, (evt, typ) in enumerate(events):
        if evt == 1:
            potions[typ].append(idx)
            picks[idx] = 0
        else:
            if potions[typ] and potions[typ][-1] < idx:
                potionIdx = potions[typ].pop()
                
                preDiff[potionIdx] += 1
                preDiff[idx] -= 1

                picks[potionIdx] = 1
            else:
                return False
    return True
            
if beatAdvs():
    # kmin, posCnt = 0, 0
    # for diff in preDiff:
    #     posCnt += diff
    #     kmin = max(posCnt, kmin)
    # print(kmin)
    
    print(max(accumulate(preDiff)))
    
    for pick in picks:
        if(pick != -1):
            print(pick, end = ' ')
else:
    print(-1)
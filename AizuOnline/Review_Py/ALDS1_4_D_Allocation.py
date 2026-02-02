N, K = map(int, input().split())
W = [int(input()) for _ in range(N)]

def loadable(p: int):
    load, truck_remain = p, K
    for w in W:
        # if w > p:
        #     return False
        if w > load:
            truck_remain -= 1
            if truck_remain <= 0:
                return False
            load = p
        load -= w
    return True
    
    # j = 0
    # for _ in range(K):
    #     load = p
    #     while j < N and W[j] <= load:
    #         load -= W[j] 
    #         j += 1
    # return j == N

# find P      optimized initial value
left, right = max(W), sum(W) + 1

while left < right:
    mid = (left + right) // 2
    if loadable(mid):
        right = mid
    else:
        left = mid + 1
print(left)
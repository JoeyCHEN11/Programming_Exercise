import heapq
n = int(input())
td = [tuple(map(int, input().split())) for _ in range(n)]
intervals = [(t, t + d) for t, d in td]

intervals.sort()
# products to be printed
pq = []
ans, timeSlot, i = 0, 0, 0
while True:
    # skip empty time
    if not pq:
        if i == n:
            break
        timeSlot = intervals[i][0]
    
    # add waiting product into pq
    while i < n and timeSlot >= intervals[i][0]:
        heapq.heappush(pq, intervals[i][1])
        i += 1
    
    # skip passed product
    while pq and pq[0] < timeSlot:
        heapq.heappop(pq)
    
    # print
    if pq and pq[0] >= timeSlot:
        heapq.heappop(pq)
        ans += 1

    timeSlot += 1
print(ans)
    
    
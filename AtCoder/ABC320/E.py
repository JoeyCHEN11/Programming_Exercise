import heapq
n, m = map(int, input().split())
noodles = [tuple(map(int, input().split())) for _ in range(m)]

# time_slot = 0
eating, row, ans = [], [i for i in range(n)], [0] * n
for t, w, s in noodles:
    while eating and eating[0][0] <= t:
        _, i = heapq.heappop(eating)
        heapq.heappush(row, i)
        
    if row:
        cus = heapq.heappop(row)
        ans[cus] += w
        heapq.heappush(eating, (t + s, cus))

for a in ans:
    print(a)
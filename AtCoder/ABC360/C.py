import heapq
n = int(input())
poses = list(map(int, input().split()))
weights = list(map(int, input().split()))

boxes = [[] for _ in range(n)]

for i, w in zip(poses, weights):
    heapq.heappush(boxes[i - 1], w)

pq = [(b[0], i) for i, b in enumerate(boxes) if len(b) > 1]
heapq.heapify(pq)
ans = 0
for b in boxes:
    if not b:
        opw, opi = heapq.heappop(pq)
        ans += opw
        heapq.heappop(boxes[opi])
        heapq.heappush(b, opw)
        
        if len(boxes[opi]) > 1:
            heapq.heappush(pq, (boxes[opi][0], opi))

print(ans)
n = int(input())

intervals = []

LEFT = 0
RIGHT = 1
for _ in range(n):
    l, r = map(int, input().split())
    intervals.append((l, LEFT))
    intervals.append((r, RIGHT))
    
intervals.sort()

ans = 0
counting = 0
for _, tp in intervals:
    if tp == RIGHT:
        counting -= 1
    else:
        ans += counting
        counting += 1

print(ans)
    
    
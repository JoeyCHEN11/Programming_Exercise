mass = [[2, 1, 0, 1],
        [1, 2, 1, 0]]

INF = int(4e9)

a, b, c, d = map(int, input().split())
ans = 0
for fx in range(4):
    for fy in range(2):
        x1 = (a - fx + INF + 3) // 4
        x2 = (c - fx + INF + 3) // 4
        countX = x2 - x1
        y1 = (b - fy + INF + 1) // 2
        y2 = (d - fy + INF + 1) // 2
        countY = y2 - y1
        ans += countX * countY * mass[fy][fx]
        
print(ans)
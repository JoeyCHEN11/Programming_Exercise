n = int(input())
sheets = [tuple(map(int, input().split())) for _ in range(n)]

cnt = 0
for x in range(101):
    for y in range(101):
        for a, b, c, d in sheets:
            if a <= x < b and c <= y < d:
                cnt += 1
                break

print(cnt)
    
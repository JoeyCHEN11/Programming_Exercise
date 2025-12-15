N, T = map(int, input().split())
color = list(map(int, input().split()))
ranks = list(map(int, input().split()))

target = T if T in color else color[0]
print(max([(r, i) for i, (c, r) in enumerate(zip(color, ranks), 1) if c == target])[1])

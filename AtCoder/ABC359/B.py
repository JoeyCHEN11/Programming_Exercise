n = int(input())
colors = list(map(int, input().split()))
colorIdx = [[] for _ in range(n)]
for i, c in enumerate(colors):
    colorIdx[c - 1].append(i)

cnt = 0
for i1, i2 in colorIdx:
    if i2 - i1 == 2:
        cnt += 1
print(cnt)
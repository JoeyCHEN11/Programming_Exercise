n, d = map(int, input().split())
s = [input() for _ in range(n)]
schedule = [[c == 'o' for c in sc] for sc in s]
# print(schedule)

maxCnt, cnt = 0, 0

for i in range(d):
    ok = True
    for j in range(n):
        if not schedule[j][i]:
            ok = False
            break
    if ok:
        cnt += 1
    else:
        cnt = 0
    maxCnt = max(maxCnt, cnt)
        
# maxCnt = max(maxCnt, cnt)
print(maxCnt)        
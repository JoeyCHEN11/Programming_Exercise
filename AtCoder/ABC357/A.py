n, m = map(int, input().split())
hands = list(map(int, input().split()))

cnt = 0
for h in hands:
    if m < h:
        break
    else:
        cnt += 1
        m -= h
        
print(cnt)
    
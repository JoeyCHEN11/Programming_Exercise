L, N1, N2 = map(int, input().split())
L1 = [tuple(map(int, input().split())) for _ in range(N1)]
L2 = [tuple(map(int, input().split())) for _ in range(N2)]

ans = 0
i, j = 0, 0
while i < N1 and j < N2:
    l = min(L1[i][1], L2[j][1])
    if L1[i][0] == L2[j][0]:
        ans += l
    
    L1[i] = L1[i][0], L1[i][1] - l
    L2[j] = L2[j][0], L2[j][1] - l
    
    if L1[i][1] == 0:
        i += 1
    if L2[j][1] == 0:
        j += 1
print(ans)
    
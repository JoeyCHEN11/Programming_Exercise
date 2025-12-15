n = int(input())
A = list(map(int, input().split()))
S = input()
mex = [[[0] * 3 for _ in range(3)] for _ in range(3)]
for i in range(3):
    for j in range(3):
        for k in range(3):
            available = [False] * 4
            available[i] = available[j] = available[k] = True
            mex[i][j][k] = available.index(False)

mL = [[0] * (n + 1) for _ in range(3)]
xR = [[0] * (n + 1) for _ in range(3)]

for i in range(1, n + 1):
    al, cl = A[i - 1], S[i - 1]
    for x in range(3):
        mL[x][i] = mL[x][i - 1]
    if cl == 'M':
        mL[al][i] += 1
        
    j = n - i
    ar, cr = A[j], S[j]
    for x in range(3):
        xR[x][j] = xR[x][j + 1]
    if cr == 'X':
        xR[ar][j] += 1

ans = 0
for i, (a, c) in enumerate(zip(A, S)):
    if c == 'E':
        for j in range(3):
            for k in range(3):
                ans += mL[j][i] * xR[k][i] * mex[j][a][k]

print(ans)
    
    
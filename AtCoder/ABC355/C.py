N, T = map(int, input().split())
A = list(map(lambda x : int(x) - 1, input().split()))

gridCheck = {N * i + j: (i, j) for j in range(N) for i in range(N)}
# for line in gridCheck.items():
#     print(line)
rows = [N] * N
cols = [N] * N
dig = [N] * 2
# print(lines)

bingoTurn = -1
for turn, a in enumerate(A, 1):
    (i, j) = gridCheck[a]
    rows[i] -= 1
    cols[j] -= 1
    if i == j: dig[0] -= 1
    if i + j == N - 1: dig[1] -= 1
    
    if rows[i] == 0 or cols[j] == 0 or dig[0] == 0 or dig[1] == 0:
        bingoTurn = turn
        break
    
print(bingoTurn)
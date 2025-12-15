n = int(input())
bets = [[False] * 37 for _ in range(n)]
C = [0] * n
for i in range(n):
    C[i] = int(input())
    for b in map(int, input().split()):
        bets[i][b - 1] = True
X = int(input()) - 1

minC = min([C[i] if bets[i][X] else 37 for i in range(n)])
        
ans = [i + 1 for i in range(n) if bets[i][X] and C[i] == minC]

print(len(ans))
for a in ans:
    print(a, end = ' ')

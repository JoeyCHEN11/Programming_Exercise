n = int(input())

taka = []
aoki = []
for _ in range(n):
    x, y = map(int, input().split())
    taka.append(x)
    aoki.append(y)

if sum(taka) == sum(aoki):
    print('Draw')
else:
    print('Takahashi' if sum(taka) > sum(aoki) else 'Aoki')
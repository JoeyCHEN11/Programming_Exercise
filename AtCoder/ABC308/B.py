n, m = map(int, input().split())
C = input().split()
D = input().split()
P = list(map(int, input().split()))

menu = {}
for i in range(m):
    menu[D[i]] = P[i + 1]

ans = 0
for c in C:
    if c in menu:
        ans += menu[c]
    else:
        ans += P[0]
        
print(ans)
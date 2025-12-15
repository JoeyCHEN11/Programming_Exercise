n, m = map(int, input().split())
s = list(map(int, input())) + [0]

maxLogo, maxAcc = 0, 0
logo, acc = 0, 0

for act in s:
    if act != 0:
        acc += 1
        if act == 2:
            logo += 1
    else:
        maxLogo = max(maxLogo, logo)
        maxAcc = max(maxAcc, acc)
        logo, acc = 0, 0

print(maxLogo + max(maxAcc - m - maxLogo, 0))
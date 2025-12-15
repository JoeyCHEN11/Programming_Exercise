n, t = map(int, input().split())
s = input()
initPos = list(map(int, input().split()))

LEFT, RIGHT = 0, 1
NEG, POS = 0, 1
ends_direct = []
for p, d in zip(initPos, s):
    if d == '0':
        l, r, direc = p - t, p, NEG
    else:
        l, r, direc = p, p + t, POS

    ends_direct.extend([(l, LEFT, direc), (r, RIGHT, direc)])

ends_direct.sort()

ans, posCnt = 0, 0
for pos, tp, direct in ends_direct:
    if direct == POS:
        if tp == LEFT:
            posCnt += 1
        else:
            posCnt -= 1
    else:
        ans += posCnt
print(ans)
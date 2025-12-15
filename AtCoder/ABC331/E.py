n, m, l = map(int, input().split())
md = list(zip(list(map(int, input().split())), [i + 1 for i in range(n)]))
sd = list(zip(list(map(int, input().split())), [i + 1 for i in range(m)]))
blocked = {tuple(map(int, input().split())) for _ in range(l)}
# print(blocked)
# md.sort(reverse=True)
sd.sort(reverse=True)

mainSets = [0] * n
for i, (mdP, c) in enumerate(md):
    setSd = 0
    matched = False
    for sdP, d in sd:
        if (c, d) not in blocked:
            setSd += sdP
            matched = True
            break
    if matched:
        mainSets[i] = setSd + mdP

print(max(mainSets))
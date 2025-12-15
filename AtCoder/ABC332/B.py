k, G, M = map(int, input().split())

glasses, mug = 0, 0
for _ in range(k):  
    if glasses == G:
        glasses = 0
    elif mug == 0:
        mug = M
    else:
        trans = min(mug, G - glasses)
        mug -= trans
        glasses += trans

print(glasses, mug)
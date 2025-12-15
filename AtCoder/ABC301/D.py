from math import log2, ceil
s = list(input())
n = int(input())

def solve(s) -> int:
    b = max(ceil(log2(n)), len(s))
    t = ['0'] * (b - len(s)) + s
    setPos = len(t)
    last = -1
    for i in range(b):
        nbit = n >> (b - (i + 1)) & 1
        if nbit == 0:
            if t[i] == '1':
                setPos = last
                break
        else:
            if t[i] == '0':
                setPos = i
                break
            if t[i] == '?':
                last = i
    
    if setPos == -1:
        return -1
    ans = 0
    for i in range(b):
        if i < b - len(s): continue
        nbit = n >> (b - (i + 1)) & 1
        ans <<= 1
        if i < setPos:
            ans |= nbit
        elif i > setPos:
            ans |= t[i] == '1' or t[i] == '?'
    return ans

print(solve(s))

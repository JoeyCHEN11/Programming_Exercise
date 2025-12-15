from re import fullmatch
s = input()


pattern = ('A', 'B', 'C')

def isABC() -> bool:
    i = 0
    n = len(s)
    for c in s:
        while i < 3 and c != pattern[i]:
            i += 1
        if i >= 3: return False
    return True


if fullmatch(r'A*B*C*', input()):
    print('Yes')
else:
    print('No')


print('Yes' if isABC() else 'No')
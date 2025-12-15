h, w = map(int, input().split())
A = [input() for _ in range(h)]
B = [input() for _ in range(h)]

exA = [r * 2 for r in (2 * A)]

def findB(ri, rj) -> bool:
    for i in range(h):
        for j in range(w):
            if B[i][j] != exA[ri + i][rj + j]:
                return False
    return True

def solve() -> bool:
    for i in range(h):
        for j in range(w):
            if findB(i, j):
                # print(i, j)
                return True
    return False

print('Yes' if solve() else 'No')
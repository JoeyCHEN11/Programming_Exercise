from itertools import combinations
n, m = map(int, input().split())
stands = [input() for _ in range(n)]
stands_bits = [0] * n

for i in range(n):
    s = stands[i]
    for c in s:
        stands_bits[i] = stands_bits[i] << 1 | (c == 'o')

def findMinComb() -> int:    
    for i in range(1, n + 1):
        for comb in combinations(stands_bits, i):
            # print(comb)
            res = 0
            for sb in comb:
                res |= sb
            if res.bit_count() == m:
                return i
    return -1

print(findMinComb())
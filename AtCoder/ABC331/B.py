from functools import cache

#  6, 8, 12
n, s, m, l = map(int, input().split())

@cache
def buyEgg(k: int) -> int:
    if k <= 0: return 0
    else: return min(s + buyEgg(k - 6), m + buyEgg(k - 8), l + buyEgg(k - 12))
    
print(buyEgg(n))
from functools import cache

n = int(input())

@cache
def divide(x: int) -> int:
    if x in (0, 1): return 0
    else: return x + divide((x + 1) // 2) + divide(x // 2)

print(divide(n))
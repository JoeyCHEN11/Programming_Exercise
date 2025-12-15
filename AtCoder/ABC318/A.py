n, m, p = map(int, input().split())
first = 1 if n >= m else 0
rest = max(n - m, 0) // p
print(first + rest)
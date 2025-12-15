M, D = map(int, input().split())
y, m, d = map(int, input().split())

y, m = y - 1, m - 1

m = m + d // D
y = y + m // M
d = d % D
m = m % M

y, m, d = y + 1, m + 1, d + 1

print(y, m, d)
n = int(input())
def truncate(x: int, b: int) -> int:
    return x - x % 10**b

ans = 0
for b in range(3, 10):
    if n < 10**b:
        ans = truncate(n, b - 3)
        break

print(ans)
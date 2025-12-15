bits = list(map(int, input().split()))
ans = 0
for b in reversed(bits):
    ans = ans << 1 | b
print(ans)

A, B = map(int, input().split())
ans = 0
while A != B:
    if A < B:
        A, B = B, A
    t = (A - 1) // B
    A -= B * t
    ans += t
print(ans)
A, M, L, R = map(int, input().split())

aoki = (R - A) // M if R - A >= 0 else (R - A + (M - 1)) // M
taka = (A - L) // M if A - L >= 0 else (A - L + (M - 1)) // M
ans = aoki + taka
if A < L:
    ans += 1 if (A - L) % M == 0 else 0
elif L <= A < R:
    ans += 1
elif R <= A:
    ans += 1 if (R - A) % M == 0 else 0
print(ans) 

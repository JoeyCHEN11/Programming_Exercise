n = int(input())
S = [input() for _ in range(n)]

def isPar(s: str) -> bool:
    return s == s[::-1]

ok = False
for i in range(n):
    for j in range(n):
        if j == i: continue
        if isPar(S[i] + S[j]):
            ok = True
            break
print('Yes' if ok else 'No')
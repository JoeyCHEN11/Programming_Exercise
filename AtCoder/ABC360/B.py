s, t = input().split()
n = len(s)
def solve():
    for w in range(1, n):
        subs = []
        for i in range(0, n, w):
            subs.append(s[i:i + w])
        # print(subs)
        for c in range(w):
            if ''.join([u[c] for u in subs if c < len(u)]) == t:
                return True
    return False

print('Yes' if solve() else 'No')
from itertools import permutations
n, m = map(int, input().split())
text = [input() for _ in range(n)]

diff = [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        for cs, ct in zip(text[i], text[j]):
            diff[i][j] += cs != ct

# print(diff)
def solve():
    for p in permutations(range(n)):
        ans = True
        for i in range(n - 1):
            # print(diff[p[i]][p[i+1]])
            ans = ans and diff[p[i]][p[i+1]] == 1
        if ans:
            return True
    return False

print('Yes' if solve() else 'No')
    

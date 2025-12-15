N, K = map(int, input().split())
s = input()
ans = ['x'] * N
k = 0
for i, c in enumerate(s):
    if c == 'o' and k < K:
        ans[i] = 'o'
        k += 1
print(''.join(ans))

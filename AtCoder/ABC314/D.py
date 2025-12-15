n = int(input())
s = list(input())
q = int(input())
queries = [tuple(map(lambda x: int(x) if x.isdigit() else x, input().split())) for _ in range(q)]
# print(queries)
NO, UPPER, LOWER = -1, 0, 1
lswitch, lswitchOrder = NO, -1
queOrder = [-1] * n
for i, (t, x, c) in enumerate(queries):
    if t != 1:
        lswitch = LOWER if t == 2 else UPPER
        lswitchOrder = i
    else:
        # print('change')
        queOrder[x - 1] = i
        s[x - 1] = c

# print(s)
ans = [''] * n
for i in range(n):
    if lswitch != NO and queOrder[i] < lswitchOrder:
        ans[i] = s[i].upper() if lswitch == UPPER else s[i].lower()
    else:
        ans[i] = s[i]

print(''.join(ans))
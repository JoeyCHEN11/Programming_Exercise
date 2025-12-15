n = int(input())
# pos[key]: the person behind key is person[key]
pos = dict(zip(map(int, input().split()), [i for i in range(1, n + 1)]))
# print(pos)
ans = [0] * n
ans[0] = pos[-1]

for i in range(1, n):
    ans[i] = pos[ans[i - 1]]
    
for a in ans:
    print(a, end=' ')
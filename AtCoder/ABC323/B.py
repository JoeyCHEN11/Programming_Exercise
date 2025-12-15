n = int(input())
result = [input() for _ in range(n)]
mark = [0 for _ in range(n)]
for i in range(n - 1):
    for j in range(i + 1, n):
        if result[i][j] == 'o':
            mark[i] += 1
        else:
            mark[j] += 1

# print(mark)
for mk, id in sorted(zip(mark, [i for i in range(1, n + 1)]), key = lambda x: (x[0], -x[1]), reverse = True):
    print(id, end=' ')














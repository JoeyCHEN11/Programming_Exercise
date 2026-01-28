N = int(input())
lis = list(map(int, input().split()))
cnt = 0

for i in range(N):
    # min_j, min_v = min(enumerate(lis[i:], i), key = lambda x: x[1])

	# optimize: slice will create copy of lists, and min value will never be used
    min_j = min(range(i, N), key = lambda k: lis[k])
    if min_j != i:
        lis[min_j], lis[i] = lis[i], lis[min_j]
        cnt += 1
        
print(*lis)
print(cnt)
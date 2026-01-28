N = int(input())
lis = list(map(int, input().split()))

for i in range(1, N):
    print(*lis)
    v = lis[i]
    j = i - 1
    while j >= 0 and lis[j] > v:
        lis[j + 1] = lis[j]
        j -= 1
    lis[j + 1] = v

print(*lis)

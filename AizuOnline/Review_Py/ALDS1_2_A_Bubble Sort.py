N = int(input())
lis = list(map(int, input().split()))

cnt = 0
is_sorted = False

while not is_sorted:
    is_sorted = True
    for i in reversed(range(1, N)):
        if lis[i] < lis[i - 1]:
            lis[i], lis[i - 1] = lis[i - 1], lis[i]
            cnt += 1
            is_sorted = False

print(*lis)
print(cnt)    

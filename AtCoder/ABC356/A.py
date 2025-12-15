n, l, r = map(int, input().split())
arr = [i for i in range(1, n + 1)]
arr[l - 1: r] = arr[l - 1: r][::-1]
for num in arr:
    print(num, end = ' ')

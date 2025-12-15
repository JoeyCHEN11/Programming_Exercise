import bisect
n, m = map(int, input().split())
sells = sorted(list(map(int, input().split())))
buys = sorted(list(map(int, input().split())))

left = 0
right = max(sells[-1], buys[-1]) + 1

while left < right:
    mid = (left + right) // 2
    si, bi = bisect.bisect_right(sells, mid), m - bisect.bisect_left(buys, mid)
    # print(mid, bi, si)
    # print('lr:', left, right)
    if bi > si:
        left = mid + 1
    else:
        right = mid

print(right)


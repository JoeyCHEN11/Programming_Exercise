N = int(input())
S = list(map(int, input().split()))
Q = int(input())
T = list(map(int, input().split()))

def binary_search(lis, x) -> int:
    left, right = 0, len(lis)
    while left < right:
        mid = (left + right) // 2
        if lis[mid] == x:
            return True
        elif lis[mid] < x:
            left = mid + 1
        elif lis[mid] > x:
            right = mid
    return False

cnt = 0
for x in T:
    cnt += binary_search(S, x)

print(cnt)


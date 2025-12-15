n = int(input())
s = [-1] * n
s[0], s[n - 1] = 0, 1
left, right = 0, n - 1

while left < right - 1:
    # print(left, right)
    mid = (left + right) // 2
    print('?', mid + 1)
    s[mid] = int(input())
    if s[mid] == s[left]:
        left = mid
    else: right = mid
print('!', left + 1)
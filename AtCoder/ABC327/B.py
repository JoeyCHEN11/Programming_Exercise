import math
b = int(input())

left, right = 1, int(math.log(b)) + 2

found = False
while(left < right):
    mid = (left + right) // 2
    # print(left, right, mid)
    x = mid**mid
    if x > b:
        right = mid
    elif x < b:
        left = mid + 1
    else:
        found = True
        break
    
print(mid if found else -1)
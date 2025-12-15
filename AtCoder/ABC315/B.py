from itertools import accumulate
m = int(input())
days = list(map(int, input().split()))

mid = sum(days) // 2
month, day = 0, 0
for i, d in enumerate(days):
    if mid < d:
        month = i + 1
        day = mid + 1
        break
    else:
        mid -= d
      
print(month, day)  

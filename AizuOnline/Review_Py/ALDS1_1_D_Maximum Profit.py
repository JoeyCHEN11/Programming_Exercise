N = int(input())
prices = [int(input()) for _ in range(N)]

prof_max, pre_min = float('-inf'), float('inf')

for p in prices:
    prof_max = max(prof_max, p - pre_min)
    pre_min = min(pre_min, p)
    
print(prof_max)
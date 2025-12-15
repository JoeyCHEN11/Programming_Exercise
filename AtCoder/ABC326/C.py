n, m = map(int, input().split())
gifts = list(map(int, input().split())) + [float('inf')]

gifts.sort()

ans, j = 0, 0
for i in range(n + 1):
    if gifts[i] - gifts[j] >= m:
        ans = max(ans, i - j)
    
    while gifts[i] - gifts[j] >= m: 
        j += 1
        
print(ans)
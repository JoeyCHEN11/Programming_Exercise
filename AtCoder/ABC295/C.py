from collections import Counter
N = int(input())
socks = Counter(list(map(int, input().split())))

ans = 0

for x in socks.values():
    ans += x // 2
    
print(ans)
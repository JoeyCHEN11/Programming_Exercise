n, s, k = map(int, input().split())

buys = [tuple(map(int, input().split())) for _ in range(n)]
sum = 0
for p, q in buys:
    sum += p * q
    
print(sum + k if sum < s else sum)
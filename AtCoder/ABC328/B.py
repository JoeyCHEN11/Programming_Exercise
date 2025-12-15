n = int(input())
days = list(map(int, input().split()))

def getRep(x: int) -> int:
    digit = x % 10
    x = x // 10
    while x:
        if x % 10 != digit:
            return 0
        x //= 10
    return digit

ans = 0
for i, days in enumerate(days, 1):
    repDig = getRep(i)
    if repDig:
        for d in range(1, days + 1):
            ans += getRep(d) == repDig
        
print(ans)
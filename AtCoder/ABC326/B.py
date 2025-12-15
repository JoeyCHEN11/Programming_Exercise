n = int(input())

def is326Like(x: int) -> bool:
    hund = x // 100
    tens = (x - hund * 100) // 10
    ones = x % 10
    return hund * tens == ones

ans = -1
for x in range(n, 920):
    if is326Like(x):
        ans = x
        break
    
print(ans)
    
    
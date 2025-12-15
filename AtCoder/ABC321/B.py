n, x = map(int, input().split())
scores = list(map(int, input().split()))

def findAn() -> int:
    
    for ans in range(101):
        stsc = sorted(scores + [ans])
        if sum(stsc[1:-1]) >= x:
            return ans
    return -1

print(findAn())
n = int(input())
balls = [input() for _ in range(n)]
check = set()

for b in balls:
    if b not in check and b[::-1] not in check:
        check.add(b)

print(len(check))
        
    
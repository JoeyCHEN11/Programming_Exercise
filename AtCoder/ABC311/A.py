n = int(input())
s = input()
check = {'A', 'B', 'C'}
cnt = 0
for c in s:
    cnt += 1
    if c in check:
        check.remove(c)
    if not check:
        break
    
print(cnt)
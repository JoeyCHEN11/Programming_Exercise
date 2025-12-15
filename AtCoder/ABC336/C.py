n = int(input()) - 1

base = 10
place = 0
ans = ['' if n else '0']

while n:
    ans.append(str((n % 5) * 2))
    n //= 5

print(''.join(reversed(ans)))
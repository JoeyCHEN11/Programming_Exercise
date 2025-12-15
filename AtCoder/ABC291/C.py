N = int(input())
s = input()
direct = {'R': (1, 0), 'L': (-1, 0), 'U': (0, 1), 'D': (0, -1)}

x, y = 0, 0
steps = set([(x,y)])
ans = False
for d in s:
    dx, dy = direct[d]
    x, y = x + dx, y + dy
    if (x, y) in steps:
        ans = True
    steps.add((x, y))
print('Yes' if ans else 'No') 
n, m, h, k = map(int, input().split())
s = input()
itemXY = set([tuple(map(int, input().split())) for _ in range(m)])
direct = {'R': (1, 0), 'L': (-1, 0), 'U': (0, 1), 'D': (0, -1)}

def move():
    x, y, health = 0, 0, h
    for c in s:
        dx, dy = direct[c]
        x, y = x + dx, y + dy
        health -= 1
        if health < 0:
            return False
        
        if (x, y) in itemXY and health < k:
            health = k
            itemXY.remove((x, y))
    return True

print('Yes' if move() else 'No')
            
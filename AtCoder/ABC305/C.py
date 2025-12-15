from collections import deque
h, w = map(int, input().split())
grid = [input() for _ in range(h)]
up, down, left, right = float('inf'), 0, float('inf'), 0
for i in range(h):
    for j in range(w):
        if grid[i][j] == '#':
            up, down, left, right = min(up, i), max(down, i + 1), min(left, j), max(right, j + 1)
def solve() -> tuple[int, int]:
    for i in range(up, down):
        for j in range(left, right):
            if grid[i][j] == '.':
                return i + 1, j + 1
    return -1, -1
ai, aj = solve()
print(ai, aj)
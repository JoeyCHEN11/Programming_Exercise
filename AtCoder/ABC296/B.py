grid = [input() for _ in range(8)]


for i in range(8):
    for j in range(8):
        if grid[i][j] == '*':
            print(chr(j + ord('a')) + str(8 - i))
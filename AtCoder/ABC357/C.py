n = int(input())
grid = [['' for _ in range(3**n)] for _ in range(3**n)]
# print(grid)

def buildGrid(left: int, right: int, up: int, down: int):
    if right - left <= 1:
        grid[left][up] = '#'
        return
    else:
        midLeft = left + (right - left) // 3
        midRight = left + 2 * (right - left) // 3 
        midUp = up + (down - up) // 3
        midDown = up + 2 * (down - up) // 3
        
        for i in range(midUp, midDown):
            for j in range(midLeft, midRight):
                grid[i][j] = '.' 
        buildGrid(left, midLeft, up, midUp)
        buildGrid(midLeft, midRight, up, midUp)
        buildGrid(midRight, right, up, midUp)
        buildGrid(left, midLeft, midUp, midDown)
        buildGrid(midRight, right, midUp, midDown)
        buildGrid(left, midLeft, midDown, down)
        buildGrid(midLeft, midRight, midDown, down)
        buildGrid(midRight, right, midDown, down)
        
buildGrid(0, 3**n, 0, 3**n)

for line in grid:
    for c in line:
        print(c, end='')
    print()    
    
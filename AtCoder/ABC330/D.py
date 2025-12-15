n = int(input())
grid = [input() for _ in range(n)]
rowsCnt = [0] * n
colsCnt = [0] * n

for i in range(n):
    for j in range(n):
        rowsCnt[i] += grid[i][j] == 'o'
        colsCnt[j] += grid[i][j] == 'o'
 
ans = 0       
for i in range(n):
    for j in range(n):
        if(grid[i][j] == 'o'):
            ans += (colsCnt[j] - 1) * (rowsCnt[i] - 1)
            
print(ans)
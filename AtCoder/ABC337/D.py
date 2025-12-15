H, W, K = list(map(int, input().split()))
grid = [input() for _ in range(H)]

# sliding window
ansHoriz = float('inf')
for i in range(H):
    left = 0
    check = {'x': 0, '.': 0, 'o': 0}
    for j in range(W):
        check[grid[i][j]] += 1
        while j - left + 1 > K:
            check[grid[i][left]] -= 1
            left += 1
        if j - left + 1 == K and check['x'] == 0:
            ansHoriz = min(ansHoriz, K - check['o'])
            
ansVert = float('inf')
for j in range(W):
    up = 0
    check = {'x': 0, '.': 0, 'o': 0}
    for i in range(H):
        check[grid[i][j]] += 1
        while i - up + 1 > K:
            check[grid[up][j]] -= 1
            up += 1
        if i - up + 1 == K and check['x'] == 0:
            ansVert = min(ansVert, K - check['o'])

ans = min(ansVert, ansHoriz)

print(-1 if ans == float('inf') else ans)
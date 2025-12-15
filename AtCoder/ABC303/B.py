from math import comb
n, m = map(int, input().split())
photos = [list(map(int, input().split())) for _ in range(m)]
friends = set()
for i in range(m):
    for j in range(n - 1):
        friends.add(tuple(sorted((photos[i][j], photos[i][j + 1]))))
    
print(comb(n, 2) - len(friends))
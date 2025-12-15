n = int(input())
ans = []
tup = []
def buildTriple(depth: int, bound: int):
    if depth >= 3:
        ans.append(tup.copy())
        return
    
    for i in range(0, bound + 1):
        # print(tup)
        tup.append(i)
        buildTriple(depth + 1, bound - i)
        tup.pop()
    
buildTriple(0, n)
# print(ans)
for x, y, z in ans:
    print(x, y, z)
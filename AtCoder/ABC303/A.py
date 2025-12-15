n = int(input())
s, t = input(), input()
ans = True
siml = {'1', 'l'}
simo = {'0', 'o'}
def similar(x, y): 
    return x == y or x in siml and y in siml or y in simo and x in simo
for x, y in zip(s, t):
    ans = ans and similar(x, y)
print('Yes' if ans else 'No')
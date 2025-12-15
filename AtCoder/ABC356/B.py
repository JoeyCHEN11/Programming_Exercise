n, m = map(int, input().split())
target = list(map(int, input().split()))
foods = [list(map(int, input().split())) for _ in range(n)]
nutrients = [0] * m
# print(target)

for day in foods:
    for i, nutri in enumerate(day):
        nutrients[i] += nutri
        
met = all([nu >= t for nu, t in zip(nutrients, target)])
print('Yes' if met else 'No')
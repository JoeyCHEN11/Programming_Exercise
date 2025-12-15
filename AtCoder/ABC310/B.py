
n, m = map(int, input().split())

class Product:
    def __init__(self, m):
        self.price = 0
        self.functions = [False] * m
    
def hasSuperior(p1: Product, p2: Product) -> bool:
    if p1.price > p2.price: p1, p2 = p2, p1
    newFunc = 0

    for f, available in enumerate(p2.functions):
        if available:
            if not p1.functions[f]:
                return False
        else:
            if p1.functions[f]:
                newFunc += 1
    
    if p1.price < p2.price or newFunc > 0:
        return True
    return False
        
products = [Product(m) for _ in range(n)]
for i in range(n):
    pcf = list(map(int, input().split()))
    # print(pcf)
    products[i].price = pcf[0]
    
    for f in pcf[2:]:
        # print(products[i].functions)
        products[i].functions[f - 1] = True

ans = False
for i in range(n - 1):
    for j in range(i + 1, n):
        if hasSuperior(products[i], products[j]):
            ans = True
            break

print('Yes' if ans else 'No')
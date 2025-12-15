k = int(input())
all321 = []

def build321():
    for i in range(1, 1<<10):
        x = 0
        for j in range(9, -1, -1):
            if i & 1 << j:
                x *= 10
                x += j
        all321.append(x)

build321()
all321.sort()
print(all321[k])
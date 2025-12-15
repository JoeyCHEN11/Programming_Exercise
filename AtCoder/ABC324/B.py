from math import log2
n = int(input())

isSmooth = False

for x in range(int(log2(n)) + 1):
    for y in range(int(log2(n) + 1)):
        if pow(2, x) * pow(3, y) == n:
            isSmooth = True
            break
        
print('Yes' if isSmooth else 'No')

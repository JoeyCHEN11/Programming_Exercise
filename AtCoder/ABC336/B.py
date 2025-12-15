n = int(input())

ctz = 0

while not n & 1:
    ctz += 1
    n >>= 1
    
print(ctz)
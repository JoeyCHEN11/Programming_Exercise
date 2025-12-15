h = int(input())

plant, i = 0, 0
while plant <= h:
    plant += 2**i
    i += 1
    
print(i)
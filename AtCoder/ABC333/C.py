n = int(input())


k = 0

a = 0
while k < n:
    a = a * 10 + 1
    b = 0
    while b < a and k < n:
        b = b * 10 + 1
        c = 0
        while c < b and k < n:
            c = c * 10 + 1
            # print(a, b, c)
            k += 1
            
print(a + b + c)

p, q = input().split()

axis = {'A': 0, 'B': 3, 'C': 4, 'D': 8, 'E': 9, 'F': 14, 'G': 23}

print(abs(axis[q] - axis[p]))
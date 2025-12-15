N, M = map(int, input().split())
A = list(map(int, input().split())) + [float('inf')]
B = list(map(int, input().split())) + [float('inf')]

idxA = [-1] * N
idxB = [-1] * M
# C = [0] * (M + N)
i, j = 0, 0
for k in range(M + N):
    if A[i] < B[j]:
        # C[k] = A[i]
        idxA[i] = k + 1
        i += 1
    else:
        # C[k] = B[i]    
        idxB[j] = k + 1
        j += 1
for x in idxA:
    print(x, end=' ')
print()
for x in idxB:
    print(x, end=' ')
    
    
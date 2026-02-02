from itertools import combinations

N, A = int(input()), list(map(int, input().split()))
Q, M = int(input()), list(map(int, input().split()))

for m in M:
    success = False
    for n in range(N + 1):
        if m in map(sum, combinations(A, n)):
            success = True
            break
    print("yes" if success else "no")

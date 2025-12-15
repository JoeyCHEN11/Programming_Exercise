import copy
n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
B = [list(map(int, input().split())) for _ in range(n)]
def rotate(M):
    temp = copy.deepcopy(M)
    for i in range(n):
        for j in range(n):
            M[i][j] = temp[n - 1 - j][i]
            
def contain(M1, M2) -> bool:
    for i in range(n):
        for j in range(n):
            if M1[i][j] == 1 and M2[i][j] == 0:
                return False
    return True

def solve() -> bool:
    for _ in range(4):
        rotate(A)
        # for r in A:
        #     print(r)
        if contain(A, B):
            return True
    return False

print('Yes' if solve() else 'No')
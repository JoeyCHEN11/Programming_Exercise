n, m = map(int, input().split())
A = list(map(lambda x : (int(x), 'a'), input().split()))
B = list(map(lambda x : (int(x), 'b'), input().split()))
# check = { a: 'a' for a in A }
# for b in B: check[b] = 'b'
# print(check)
piano = False
seq = sorted(A + B)
for i in range(m + n - 1):
    # print(seq[i])
    if seq[i][1] == seq[i + 1][1] == 'a':
        piano = True
        break
    
print('Yes' if piano else 'No')
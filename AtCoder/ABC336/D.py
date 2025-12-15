n = int(input())
A = list(map(int, input().split()))

# longest lenth of left half-pyramid sequece END with A[i - 1] 
dpL = [0] * (n + 2)
# longest lenth of right half-pyramid sequece START with A[i - 1]
dpR = [0] * (n + 2)

for i in range(1, n + 1):
    # print(i)
    dpL[i] = min(A[i - 1], dpL[i - 1] + 1)
for i in range(n, 0, -1):
    dpR[i] = min(A[i - 1], dpR[i + 1] + 1)
    
print(max([min(dpL[i], dpR[i]) for i in range(0, n + 2) ]))
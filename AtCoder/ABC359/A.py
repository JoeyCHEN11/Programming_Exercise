from collections import Counter
n = int(input())
names = [input() for _ in range(n)]

print(Counter(names)['Takahashi'])
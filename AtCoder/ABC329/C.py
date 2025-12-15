from collections import defaultdict
n = int(input())
s = input() + '#'

cnt, j = 0, 0
check = defaultdict(int)

for i in range(n + 1):
    if s[i] != s[j]:
        while j < i:
            if i - j > check[s[j]]:
                cnt += (i - j) - check[s[j]]
                check[s[j]] = i - j
            j += 1
    
print(cnt)
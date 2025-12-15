from collections import Counter
s = input()
counts = Counter(s)

ans = min(counts.items(), key = lambda x : (-x[1], x[0]))
        
print(ans[0])
s = list(input())
print('Yes' if len(s) == len(set(s)) and s == sorted(s, reverse=True) else 'No')

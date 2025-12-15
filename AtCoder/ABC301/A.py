n = int(input())
s = input()
a, t = s.count('A'), s.count('T')

if a == t:
    print('A' if s[-1] == 'T' else 'T')
else:
    print('A' if a > t else 'T')
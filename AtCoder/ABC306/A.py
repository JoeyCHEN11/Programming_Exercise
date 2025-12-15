n = int(input())
s = input()
print(''.join([''.join(dup) for dup in zip(s, s)]))
s = input()
print([i for i, c in enumerate(s) if c.isupper()][0] + 1)
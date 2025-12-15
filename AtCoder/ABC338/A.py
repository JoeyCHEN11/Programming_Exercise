s = input()

print('Yes') if s[0].isupper() and (not s[1:] or s[1:].islower()) else print('No')
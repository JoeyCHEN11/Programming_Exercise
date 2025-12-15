import re
n, s = int(input()), input()

print('Yes' if re.search('ab', s) or re.search('ba', s) else 'No')

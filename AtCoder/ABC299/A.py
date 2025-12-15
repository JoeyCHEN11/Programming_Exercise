import re
n = int(input())
s = input()
left, mid, right = s.find('|'), s.find('*'), s.rfind('|')
print('in' if left < mid < right else 'out')

# print('in' if re.fullmatch(r'.*\|.*\*.*\|.*', s) else 'out')
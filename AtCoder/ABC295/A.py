n = int(input())
words = input().split()
dictionary = { 'and', 'not', 'that', 'the', 'you'}
print('Yes' if any([w in dictionary for w in words]) else 'No')
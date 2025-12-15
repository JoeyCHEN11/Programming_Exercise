n, a, b = map(int, input().split())
choice = list(map(int, input().split()))
print(choice.index(a + b) + 1)
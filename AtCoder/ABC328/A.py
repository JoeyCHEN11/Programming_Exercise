n, x = map(int, input().split())
scores = list(map(int, input().split()))

print(sum([s for s in scores if s <= x]))

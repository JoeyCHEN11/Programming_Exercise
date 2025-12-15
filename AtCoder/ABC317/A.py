import bisect
n, h, x = map(int, input().split())
potions = list(map(int, input().split()))
print(bisect.bisect_left(potions, x - h) + 1)
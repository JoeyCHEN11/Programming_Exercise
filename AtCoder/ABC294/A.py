N = int(input())
nums = list(map(int, input().split()))
for x in [x for x in nums if x % 2 == 0]:
    print(x, end= ' ')
import heapq
n = int(input())
nums = list(map(int, input().split()))
print(heapq.nlargest(2, set(nums))[1])
